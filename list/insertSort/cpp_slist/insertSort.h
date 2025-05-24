#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> Insert(const T1 &arg1, const slist<T1> &arg2) {
    // Insert a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = arg1;
        return slist<T1>::sCons(a, slist<T1>::sNil());
    }

    // Insert a (sCons x xs) =(if a \<le> x then (sCons a (sCons x xs)) else (sCons x (Insert a xs)))
    auto a = arg1;
    auto x = arg2.as_sCons().p1();
    auto xs = arg2.as_sCons().p2();
    slist<T1> temp2;
    if (a <= x) {
        temp2 = slist<T1>::sCons(a, slist<T1>::sCons(x, xs));
    } else {
        temp2 = slist<T1>::sCons(x, Insert(a, xs));
    }
    return temp2;
}


template<typename T1>
slist<T1> InsertSortPart(const slist<T1> &arg1, const slist<T1> &arg2) {
    // InsertSortPart sNil ys=ys
    if (arg1.is_sNil()) {
        auto ys = arg2.self();
        return ys;
    }

    // InsertSortPart (sCons x xs) ys=InsertSortPart xs (Insert x ys)
    auto x = arg1.as_sCons().p1();
    auto xs = arg1.as_sCons().p2();
    auto ys = arg2.self();
    auto temp0 = Insert(x, ys);
    return InsertSortPart(xs, temp0);
}


template<typename T1>
slist<T1> InsertSort(const slist<T1> &arg1) {
    // InsertSort xs = InsertSortPart xs sNil
    auto xs = arg1.self();
    return InsertSortPart(xs, slist<T1>::sNil());
}

