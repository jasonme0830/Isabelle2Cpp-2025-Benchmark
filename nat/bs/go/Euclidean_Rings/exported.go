package Euclidean_Rings

import (
  // "isabelle/exported/HOL"
  "isabelle/exported/Nat"
  "isabelle/exported/Product_Type"
)

func Divmod_nat (m Nat.Nata, n Nat.Nata) Product_Type.Prod[Nat.Nata, Nat.Nata] {
  target := Nat.Equal_nat(n, Nat.Nata(Nat.Zero_nat{})) || Nat.Less_nat(m, n);
  {
    if target == (true) {
      return Product_Type.Prod[Nat.Nata, Nat.Nata]{Nat.Nata(Nat.Zero_nat{}), m};
    }
  };
  {
    if target == (false) {
      targeu := Divmod_nat(Nat.Minus_nat(m, n), n);
      {
        _ = targeu;
        q, a := Product_Type.Pair_dest(targeu);
        return Product_Type.Prod[Nat.Nata, Nat.Nata]{Nat.Nata(Nat.Suc{q}), a};
      };
      panic("match failed");
    }
  };
  panic("match failed");
}

func Divide_nat (m Nat.Nata, n Nat.Nata) Nat.Nata {
  return Product_Type.Fst[Nat.Nata, Nat.Nata](Divmod_nat(m, n));
}
