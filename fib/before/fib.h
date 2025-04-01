#include <cstdint>
#include <cstdlib>

std::uint64_t fib(std::uint64_t arg1) {
    // fib 0 = 1
    if (arg1 == 0) {
        return 1;
    }

    // fib (Suc 0) = 1
    if (arg1 != 0) {
        if (arg1 - 1 == 0) {
            return 1;
        }
    }

    // fib n = (fib (n - 1)) + (fib (n - 2))
    auto n = arg1;
    return fib(n - 1) + fib(n - 2);
}