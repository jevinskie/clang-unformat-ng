#include "clang-unformat-ng/style.hpp"
#include <string>
#include <vector>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>

#include <fmt/format.h>

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
    // fmt::print("vreps:\n{}\n", fmt::join(vreps, ", "));
    // for (const auto &[path, vrep] : vreps) {
    //     fmt::print("\n[!] path: {}\n", path);
    //     const auto &freps = vrep.replacements;
    //     size_t i          = 0;
    //     for (const auto &r : freps) {
    //         fmt::print("[{:4d}]: {}\n", i, r);
    //     }
    // }

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
