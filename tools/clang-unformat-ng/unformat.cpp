#include <string>
#include <vector>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>

#include <fmt/format.h>

#include <clang-unformat-ng/clang-unformat-ng.hpp>

using namespace llvm;

namespace {

static cl::OptionCategory UnformatOptionsCategory("unformat");
static cl::list<std::string> FileNames(cl::Positional, cl::desc("[<file> ...]"), cl::cat(UnformatOptionsCategory));

int priv_main() {
    std::vector<std::string> fnames(FileNames.begin(), FileNames.end());
    for (const auto &f : fnames) {
        fmt::print("file: {}\n", f);
    }

    return 0;
}

}; // namespace

int main(int argc, const char **argv) {
    InitLLVM X(argc, argv);
    cl::HideUnrelatedOptions(UnformatOptionsCategory);
    cl::ParseCommandLineOptions(argc, argv, "A tool to calculate \"optimal\" format styles from existing source.\n\n");
    int res = priv_main();
    return res;
}
