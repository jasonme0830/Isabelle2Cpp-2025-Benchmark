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

func Less_eq_nat (x0 Nata, n Nata) bool {
  {
    q, m := x0.(Suc);
    if m {
      ma := Suc_dest(q);
      nb := n;
      return Less_nat(ma, nb);
    }
  };
  {
    if x0 == (Nata(Zero_nat{})) {
      return true;
    }
  };
  panic("match failed");
}

func Less_nat (m Nata, x1 Nata) bool {
  {
    mb := m;
    q, n := x1.(Suc);
    if n {
      na := Suc_dest(q);
      return Less_eq_nat(mb, na);
    }
  };
  {
    if x1 == (Nata(Zero_nat{})) {
      return false;
    }
  };
  panic("match failed");
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

func Equal_nat (x0 Nata, x1 Nata) bool {
  {
    if x0 == (Nata(Zero_nat{})) {
      _, m := x1.(Suc);
      if m {
        return false;
      }
    }
  };
  {
    _, m := x0.(Suc);
    if m {
      if x1 == (Nata(Zero_nat{})) {
        return false;
      }
    }
  };
  {
    q, m := x0.(Suc);
    if m {
      x2a := Suc_dest(q);
      q, m := x1.(Suc);
      if m {
        y2a := Suc_dest(q);
        return Equal_nat(x2a, y2a);
      }
    }
  };
  {
    if x0 == (Nata(Zero_nat{})) {
      if x1 == (Nata(Zero_nat{})) {
        return true;
      }
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
