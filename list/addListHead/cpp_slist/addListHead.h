#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <map>
#include <optional>
#include <list>
#include <variant>
#include <memory>

#include "../../../AgenType/newType.h"

template<typename T1>
slist<T1> AddListHead(const T1 &arg1, const slist<T1> &arg2) {
    // AddListHead a xs = sCons a  xs
    auto a = arg1;
    auto xs = arg2.self();
    return slist<T1>::sCons(a, xs);
}
