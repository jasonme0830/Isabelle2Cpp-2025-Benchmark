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
std::deque<T1> AddListHead(const T1 &arg1, const std::deque<T1> &arg2) {
    // AddListHead a xs =a # xs
    auto a = arg1;
    auto xs = arg2;
    auto temp0 = std::move(xs);
    temp0.push_front(std::move(a));
    return temp0;
}
