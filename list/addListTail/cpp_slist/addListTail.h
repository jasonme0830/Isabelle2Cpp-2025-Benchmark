#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> AddListTail(const T1 &arg1, const slist<T1> &arg2) {
    // AddListTail a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = arg1;
        return slist<T1>::sCons(a, slist<T1>::sNil());
    }

    // AddListTail a (sCons x xs) = sCons x  (AddListTail a xs )
    auto a = arg1;
    auto x = arg2.as_sCons().p1();
    auto xs = arg2.as_sCons().p2();
    return slist<T1>::sCons(x, AddListTail(a, xs));
}


