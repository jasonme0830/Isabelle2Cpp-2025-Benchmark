#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> AddListHead(const T1 &arg1, const slist<T1> &arg2) {
    // AddListHead a xs = sCons a  xs
    auto a = arg1;
    auto xs = arg2.self();
    return slist<T1>::sCons(a, xs);
}


template<typename T1>
slist<T1> AddListI(const std::uint64_t &arg1, const T1 &arg2, const slist<T1> &arg3) {
    // AddListI i a sNil = sCons a sNil
    if (arg3.is_sNil()) {
        auto a = arg2;
        return slist<T1>::sCons(a, slist<T1>::sNil());
    }

    // AddListI Zero a xs = AddListHead a xs
    if (arg1 == 0) {
        auto a = arg2;
        auto xs = arg3.self();
        return AddListHead(a, xs);
    }

    // AddListI (Suc i) a (sCons x xs) = sCons x  (AddListI i a xs)
    auto i = arg1 - 1;
    auto a = arg2;
    auto x = arg3.as_sCons().p1();
    auto xs = arg3.as_sCons().p2();
    return slist<T1>::sCons(x, AddListI(i, a, xs));
}