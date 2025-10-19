#include <nanobind/nanobind.h>

int add(int a, int b) {
    return a + b;
}

NB_MODULE(clang_unformat_ng_py_ffi, m) {
    m.def("add", &add);
}
