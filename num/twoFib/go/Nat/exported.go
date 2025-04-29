package Nat

import (
)

// sum type which can be Zero_nat, Suc
type Nata any;
type Zero_nat struct {
};
type Suc struct {
  A Nata;
};

func Suc_dest(p Suc)(Nata) {
  return p.A
}

func One_nat () Nata {
  return Nata(Suc{Nata(Zero_nat{})});
}

func Plus_nat (x0 Nata, n Nata) Nata {
  {
    q, m := x0.(Suc);
    if m {
      ma := Suc_dest(q);
      nb := n;
      return Plus_nat(ma, Nata(Suc{nb}));
    }
  };
  {
    if x0 == (Nata(Zero_nat{})) {
      nb := n;
      return nb;
    }
  };
  panic("match failed");
}

func Minus_nat (m Nata, n Nata) Nata {
  {
    q, o := m.(Suc);
    if o {
      mb := Suc_dest(q);
      q, o := n.(Suc);
      if o {
        nb := Suc_dest(q);
        return Minus_nat(mb, nb);
      }
    }
  };
  {
    if m == (Nata(Zero_nat{})) {
      return Nata(Zero_nat{});
    }
  };
  {
    mb := m;
    if n == (Nata(Zero_nat{})) {
      return mb;
    }
  };
  panic("match failed");
}
