#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <map>
#include <optional>
#include <list>
#include <variant>
#include <memory>

template<typename T1>
bool SearchList(T1 arg1, std::deque<T1> arg2) {
    // SearchList a [] = False
    if (arg2.empty()) {
        return false;
    }

    // SearchList a (x#xs) = (if a=x then True else (SearchList a xs))
    auto a = std::move(arg1);
    auto x = arg2.front();
    arg2.erase(arg2.begin(), arg2.begin() + 1);
    auto xs = std::move(arg2);
    bool temp0;
    if (a == x) {
        temp0 = true;
    } else {
        temp0 = SearchList(std::move(a), std::move(xs));
    }
    return temp0;
}
