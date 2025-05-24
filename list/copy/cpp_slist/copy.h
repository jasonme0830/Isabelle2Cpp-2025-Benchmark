#include "../../../AgenType/newType.h"

template<typename T1>
slist<T1> copyList(const slist<T1> &arg1) {
    // copyList sNil = sNil
    if (arg1.is_sNil()) {
        return slist<T1>::sNil();
    }

    // copyList (sCons x xs) = sCons x (copyList xs)
    auto x = arg1.as_sCons().p1();
    auto xs = arg1.as_sCons().p2();
    return slist<T1>::sCons(x, copyList(xs));
}

