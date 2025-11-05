#include <chrono>
#include <cstdlib>
#include <optional>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include <fmt/format.h>
#include <rfl.hpp>
#include <rfl/json.hpp>

#include <clang-unformat-ng/clang-unformat-ng.hpp>

#ifndef UNFMTNG_DISABLE_LLVM
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>
#else
#include <clang-unformat-ng/llvm-stubs.hpp>
#include <flags.h>
#endif

using namespace llvm;

namespace unformat {
namespace priv {

#ifndef UNFMTNG_DISABLE_LLVM
static cl::OptionCategory UnformatOptionsCategory("unformat");
static cl::list<std::string> FileNames(cl::Positional, cl::desc("[<file> ...]"), cl::cat(UnformatOptionsCategory));
static cl::opt<std::string> Serve("s", cl::desc("Run in server mode"), cl::value_desc("domain socket path"),
                                  cl::cat(UnformatOptionsCategory));
static cl::opt<bool> Etc("e", cl::desc("Run etc sketch code"), cl::cat(UnformatOptionsCategory));
#else
template <typename T> struct cli_opt_t : public std::optional<T> {
    auto hasValue() const {
        return this->has_value();
    }
    auto getValue() {
        if (!this->has_value()) {
            std::abort();
        }
        return this->value();
    }
};

struct cli_str_opt_t : cli_opt_t<std::string> {
    auto empty() const {
        return !this->has_value() || this->value().empty();
    }
};

static std::vector<std::string> FileNames;
static cli_str_opt_t Serve;
static cli_opt_t<bool> Etc;

static void priv_main_parse_args(int argc, char **argv) {
    const flags::args args(argc, argv);
    for (const auto pos_sv : args.positional()) {
        FileNames.push_back(std::string(pos_sv));
    }
    if (auto s_opt = args.get<std::string_view>("s")) {
        fmt::print(stderr, "*s_opt: {}\n", *s_opt);
        Serve.emplace(*s_opt);
    }
    if (auto e_opt = args.get<bool>("e")) {
        fmt::print(stderr, "*e_opt: {}\n", *e_opt);
        Etc.emplace(*e_opt);
    }
}
#endif

static result<void> sandbox() {
    std::vector<std::string> fnames(FileNames.begin(), FileNames.end());
    for (const auto &f : fnames) {
        fmt::print("file: {}\n", f);
    }
    BOOST_LEAF_AUTO(vfs, construct_vfs(fnames));
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

    // const auto cstyle = get_style(builtin_style_t::none);
    // fmt::print("cstyle: json: {}\n", rfl::json::write(cstyle));

    // const auto st = rpc_cmd_t::RPC_HELLO;
    // fmt::print("st: json: {}\n", rfl::json::write(st));

    const auto h_req = rpc_cmd::get_style_req{builtin_style_t::llvm};
    fmt::print("h_req: json: {}\n", rfl::json::write(h_req));
    const auto h_resp = rpc_cmd::get_style_resp{true, "{\"como esta\"}"};
    fmt::print("h_resp: json: {}\n", rfl::json::write(h_resp));
    fmt::print("var_resp<h_resp>: json: {}\n", rfl::json::write<rfl::AddTagsToVariants>(rpc_cmd::response_t{h_resp}));
    return {};
}

static int priv_main() {
    leaf::try_handle_all(
        []() -> leaf::result<void> {
            if (Etc) {
                (void)BOOST_LEAF_CHECK(sandbox());
            } else if (!Serve.empty()) {
                // UnixSocket s{Serve.getValue()};
                auto server      = RPCServer(Serve.getValue());
                auto stop_source = server.run();
                fmt::print(stderr, "priv_main server running\n");
                // for (int i = 0; i < 4; ++i) {
                while (!stop_source.stop_requested()) {
                    // fmt::print(stderr, "main loop inner\n");
                    std::this_thread::sleep_for(std::chrono::milliseconds{50});
                }
                fmt::print(stderr, "main request stop\n");
                stop_source.request_stop();
                fmt::print(stderr, "main end serve\n");
            }
            return {};
        },
        []() -> void {
            fmt::print(stderr, "unformat-ng priv_main other error\n");
        });
    return 0;
}
} // namespace priv
} // namespace unformat

int main(int argc, char **argv) {
#ifndef UNFMTNG_DISABLE_LLVM
    InitLLVM X(argc, argv);
    cl::HideUnrelatedOptions(unformat::priv::UnformatOptionsCategory);
    cl::ParseCommandLineOptions(argc, argv, "A tool to calculate \"optimal\" format styles from existing source.\n\n");
#else
    unformat::priv::priv_main_parse_args(argc, argv);
#endif
    int res = unformat::priv::priv_main();
    return res;
}
