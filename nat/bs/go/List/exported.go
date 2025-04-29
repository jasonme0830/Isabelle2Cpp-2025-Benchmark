package List

import (
  "isabelle/exported/Nat"
)

// sum type which can be Nil, Cons
type Lista[a any] any;
type Nil[a any] struct {
};
type Cons[a any] struct {
  A a;
  Aa Lista[a];
};

func Cons_dest[a any](p Cons[a])(a, Lista[a]) {
  return p.A, p.Aa
}

func Nth[a any] (x0 Lista[a], x1 Nat.Nata) a {
  {
    q, m := x0.(Cons[a]);
    if m {
      _, xsa := Cons_dest(q);
      q, m := x1.(Nat.Suc);
      if m {
        na := Nat.Suc_dest(q);
        return Nth[a](xsa, na);
      }
    }
  };
  {
    q, m := x0.(Cons[a]);
    if m {
      xa, _ := Cons_dest(q);
      if x1 == (Nat.Nata(Nat.Zero_nat{})) {
        return xa;
      }
    }
  };
  panic("match failed");
}

func Drop[a any] (n Nat.Nata, x1 Lista[a]) Lista[a] {
  {
    if x1 == (Lista[a](Nil[a]{})) {
      return Lista[a](Nil[a]{});
    }
  };
  {
    nb := n;
    q, m := x1.(Cons[a]);
    if m {
      xa, xsa := Cons_dest(q);
      target := nb;
      {
        if target == (Nat.Nata(Nat.Zero_nat{})) {
          return Lista[a](Cons[a]{xa, xsa});
        }
      };
      {
        q, m := target.(Nat.Suc);
        if m {
          ma := Nat.Suc_dest(q);
          return Drop[a](ma, xsa);
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}

func Take[a any] (n Nat.Nata, x1 Lista[a]) Lista[a] {
  {
    if x1 == (Lista[a](Nil[a]{})) {
      return Lista[a](Nil[a]{});
    }
  };
  {
    nb := n;
    q, m := x1.(Cons[a]);
    if m {
      xa, xsa := Cons_dest(q);
      target := nb;
      {
        if target == (Nat.Nata(Nat.Zero_nat{})) {
          return Lista[a](Nil[a]{});
        }
      };
      {
        q, m := target.(Nat.Suc);
        if m {
          ma := Nat.Suc_dest(q);
          return Lista[a](Cons[a]{xa, Take[a](ma, xsa)});
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}

func Gen_length[a any] (n Nat.Nata, x1 Lista[a]) Nat.Nata {
  {
    nb := n;
    q, m := x1.(Cons[a]);
    if m {
      _, xsa := Cons_dest(q);
      return Gen_length[a](Nat.Nata(Nat.Suc{nb}), xsa);
    }
  };
  {
    nb := n;
    if x1 == (Lista[a](Nil[a]{})) {
      return nb;
    }
  };
  panic("match failed");
}

func Size_list[a any] () func(Lista[a]) Nat.Nata {
  return func  (aa Lista[a]) Nat.Nata {
           return Gen_length[a](Nat.Nata(Nat.Zero_nat{}), aa);
         };
}
