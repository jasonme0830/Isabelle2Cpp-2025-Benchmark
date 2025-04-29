package Num

import (
  // "isabelle/exported/HOL"
  "isabelle/exported/Nat"
)

// sum type which can be One, Bit0, Bit1
type Numa any;
type One struct {
};
type Bit0 struct {
  A Numa;
};
type Bit1 struct {
  A Numa;
};

func Bit0_dest(p Bit0)(Numa) {
  return p.A
}
func Bit1_dest(p Bit1)(Numa) {
  return p.A
}

func Nat_of_num (x0 Numa) Nat.Nata {
  {
    q, m := x0.(Bit1);
    if m {
      na := Bit1_dest(q);
      m := Nat_of_num(na);
      return Nat.Nata(Nat.Suc{Nat.Plus_nat(m, m)});
    }
  };
  {
    q, m := x0.(Bit0);
    if m {
      na := Bit0_dest(q);
      m := Nat_of_num(na);
      return Nat.Plus_nat(m, m);
    }
  };
  {
    if x0 == (Numa(One{})) {
      return Nat.One_nat();
    }
  };
  panic("match failed");
}
