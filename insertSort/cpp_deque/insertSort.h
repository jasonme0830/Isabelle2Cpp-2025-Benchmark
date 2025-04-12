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

template<typename T1>
std::deque<T1> InsertSortPart(std::deque<T1> arg1, std::deque<T1> arg2) {
    // InsertSortPart [] ys=ys
    if (arg1.empty()) {
        auto ys = std::move(arg2);
        return ys;
    }

    // InsertSortPart (x#xs) ys=InsertSortPart xs (Insert x ys)
    auto x = arg1.front();
    arg1.erase(arg1.begin(), arg1.begin() + 1);
    auto xs = std::move(arg1);
    auto ys = std::move(arg2);
    auto temp0 = std::move(x);
    auto temp1 = std::move(ys);
    return InsertSortPart(std::move(xs), Insert(std::move(temp0), std::move(temp1)));
}

template<typename T1>
std::deque<T1> InsertSort(const std::deque<T1> &arg1) {
    // InsertSort xs = InsertSortPart xs Nil
    auto xs = arg1;
    auto temp0 = std::move(xs);
    auto temp1 = std::deque<T1>();
    return InsertSortPart(std::move(temp0), std::move(temp1));
}
