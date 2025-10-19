#include <nanobind/nanobind.h>

namespace nb = nanobind;

using namespace nb::literals;

int add(int a, int b) {
    return a + b;
}

NB_MODULE(cxx_py_ffi, m) {
    m.def("add", &add);
}
