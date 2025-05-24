#include "../../../AgenType/newType.h"


template<typename T1>
bool SearchList(const T1 &arg1, const slist<T1> &arg2) {
    // SearchList a sNil = False
    if (arg2.is_sNil()) {
        return false;
    }

    // SearchList a (sCons x xs) = (if a=x then True else (SearchList a xs))
    auto a = arg1;
    auto x = arg2.as_sCons().p1();
    auto xs = arg2.as_sCons().p2();
    bool temp2;
    if (a == x) {
        temp2 = true;
    } else {
        temp2 = SearchList(a, xs);
    }
    return temp2;
}

