#include "../../../AgenType/newType.h"



template<typename T1>
bool SearchList(T1 arg1, slist<T1> arg2) {
    // SearchList a sNil = False
    if (arg2.is_sNil()) {
        return false;
    }

    // SearchList a (sCons x xs) = (if a=x then True else (SearchList a xs))
    auto a = std::move(arg1);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    bool temp0;
    if (a == x) {
        temp0 = true;
    } else {
        temp0 = SearchList(std::move(a), std::move(xs));
    }
    return temp0;
}