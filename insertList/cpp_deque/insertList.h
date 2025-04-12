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
std::deque<T1> Insert(T1 arg1, std::deque<T1> arg2) {
    // Insert a [] =Cons a []
    if (arg2.empty()) {
        auto a = std::move(arg1);
        auto temp0 = std::deque<T1>();
        temp0.push_front(std::move(a));
        return temp0;
    }

    // Insert a (x#xs) =(if a \<le> x then a#x#xs else x#(Insert a xs))
    auto a = std::move(arg1);
    auto x = arg2.front();
    arg2.erase(arg2.begin(), arg2.begin() + 1);
    auto xs = std::move(arg2);
    std::deque<T1> temp0;
    if (a <= x) {
        auto temp1 = std::move(xs);
        temp1.push_front(std::move(x));
        auto temp2 = std::move(temp1);
        temp2.push_front(std::move(a));
        temp0 = std::move(temp2);
    } else {
        auto temp3 = Insert(std::move(a), std::move(xs));
        temp3.push_front(std::move(x));
        temp0 = std::move(temp3);
    }
    return temp0;
}
