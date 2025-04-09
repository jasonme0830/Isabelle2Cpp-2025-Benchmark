#include <cstdint>
#include <cstdlib>
#include <map>

std::uint64_t fib(const std::uint64_t &arg1) {
    auto impl = [&]() -> std::uint64_t {
        // fib 0 = 0
        if (arg1 == 0) {
            return 0;
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
    };

    static std::map<std::tuple<std::uint64_t>, std::uint64_t> cache;
    auto args = std::make_tuple(arg1);
    auto it = cache.find(args);
    return it != cache.end() ? it->second : (cache.emplace(std::move(args), impl()).first->second);
}