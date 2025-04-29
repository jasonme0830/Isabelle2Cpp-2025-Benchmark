#include "../../../AgenType/newType.h"



template<typename T1>
slist<T1> Insert(T1 arg1, slist<T1> arg2) {
    // Insert a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = std::move(arg1);
        auto temp0 = slist<T1>::sCons(
            std::move(a),
            slist<T1>::sNil()
        );
        return temp0;
    }

    // Insert a (sCons x xs) =(if a \<le> x then (sCons a (sCons x xs)) else (sCons x (Insert a xs)))
    auto a = std::move(arg1);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    slist<T1> temp0;
    if (a <= x) {
        auto temp1 = slist<T1>::sCons(
            std::move(x),
            std::move(xs)
        );
        auto temp2 = slist<T1>::sCons(
            std::move(a),
            std::move(temp1)
        );
        temp0 = std::move(temp2);
    } else {
        auto temp3 = slist<T1>::sCons(
            std::move(x),
            Insert(std::move(a), std::move(xs))
        );
        temp0 = std::move(temp3);
    }
    return temp0;
}

template<typename T1>
slist<T1> InsertSortPart(slist<T1> arg1, slist<T1> arg2) {
    // InsertSortPart sNil ys=ys
    if (arg1.is_sNil()) {
        auto ys = std::move(arg2);
        return ys;
    }

    // InsertSortPart (sCons x xs) ys=InsertSortPart xs (Insert x ys)
    auto x = std::move(arg1.as_sCons().p1_);
    auto xs = std::move(*arg1.as_sCons().p2_);
    auto ys = std::move(arg2);
    auto temp0 = std::move(x);
    auto temp1 = std::move(ys);
    return InsertSortPart(std::move(xs), Insert(std::move(temp0), std::move(temp1)));
}

template<typename T1>
slist<T1> InsertSort(slist<T1> arg1) {
    // InsertSort xs = InsertSortPart xs sNil
    auto xs = std::move(arg1);
    auto temp0 = std::move(xs);
    auto temp1 = slist<T1>::sNil();
    return InsertSortPart(std::move(temp0), std::move(temp1));
}
