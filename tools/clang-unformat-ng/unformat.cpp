#include "clang-unformat-ng/rpc.hpp"
#include "clang-unformat-ng/style.hpp"
#include <string>
#include <vector>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>

#include <fmt/format.h>
#include <rfl.hpp>
#include <rfl/json.hpp>

#include <clang-unformat-ng/clang-unformat-ng.hpp>

using namespace llvm;

namespace unformat {
namespace priv {

static cl::OptionCategory UnformatOptionsCategory("unformat");
static cl::list<std::string> FileNames(cl::Positional, cl::desc("[<file> ...]"), cl::cat(UnformatOptionsCategory));

int priv_main() {
    std::vector<std::string> fnames(FileNames.begin(), FileNames.end());
    for (const auto &f : fnames) {
        fmt::print("file: {}\n", f);
    }
    auto vfs = construct_vfs(fnames);
    fmt::print("vfs:\n{}\n", vfs);
    const auto style = random_style_enum();
    fmt::print("style: {}\n", style_name(style));
    auto vreps = reformat_vfs(vfs, style);
    fmt::print("vreps.size(): {}\n", vreps.size());
    for (const auto &[path, vrep] : vreps) {
        fmt::print("\n[!] path: {}\n", path);
        const auto &freps = vrep.replacements;
        size_t i          = 0;
        for (const auto &r : freps) {
            fmt::print("[{:4d}]: off: {} sz: {}\n", i, r.getOffset(), r.getLength());
            ++i;
        }
    }

    const auto foo = style::Type{"foo", "bar", false, true, false};
    fmt::print("foo json: {}\n", rfl::json::write(foo));

    const auto v1 = style::Version{4};
    fmt::print("version 4.None: {}\n", rfl::json::write(v1));

    const auto nf = style::NestedField{"nf", foo, v1};
    fmt::print("nf json: {}\n", rfl::json::write(nf));
    const auto nf_nover = style::NestedField{"nf", foo};
    fmt::print("nf_nover json: {}\n", rfl::json::write(nf_nover));

    fmt::print("rpc_cmd::FormatReq json: {}\n", rfl::json::write(rpc_cmd::format_req{}));

    const auto cstyle = get_style(builtin_style_t::none);
    fmt::print("cstyle: json: {}\n", rfl::json::write(cstyle));

    // const auto st = rpc_cmd_t::RPC_HELLO;
    // fmt::print("st: json: {}\n", rfl::json::write(st));

    const auto h_req = rpc_cmd::get_style_req{builtin_style_t::llvm};
    fmt::print("h_req: json: {}\n", rfl::json::write(h_req));
    const auto h_resp = rpc_cmd::get_style_resp{true, "{\"como esta\"}"};
    fmt::print("h_resp: json: {}\n", rfl::json::write(h_resp));
    fmt::print("var_resp<h_resp>: json: {}\n", rfl::json::write<rfl::AddTagsToVariants>(rpc_cmd::response_t{h_resp}));

    return 0;
}
}; // namespace priv
}; // namespace unformat

int main(int argc, const char **argv) {
    InitLLVM X(argc, argv);
    cl::HideUnrelatedOptions(unformat::priv::UnformatOptionsCategory);
    cl::ParseCommandLineOptions(argc, argv, "A tool to calculate \"optimal\" format styles from existing source.\n\n");
    int res = unformat::priv::priv_main();
    return res;
}
