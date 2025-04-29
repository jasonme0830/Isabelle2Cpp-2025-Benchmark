package DelListI

import (
  "isabelle/exported/Nat"
  "isabelle/exported/List"
)

func DelListHead[a any] (x0 List.Lista[a]) List.Lista[a] {
  {
    q, m := x0.(List.Cons[a]);
    if m {
      _, xsa := List.Cons_dest(q);
      return xsa;
    }
  };
  {
    if x0 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Nil[a]{});
    }
  };
  panic("match failed");
}

func DelListIa[a any] (i Nat.Nata, x1 List.Lista[a]) List.Lista[a] {
  {
    if x1 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Nil[a]{});
    }
  };
  {
    q, m := x1.(List.Cons[a]);
    if m {
      _, c := List.Cons_dest(q);
      if c == (List.Lista[a](List.Nil[a]{})) {
        return List.Lista[a](List.Nil[a]{});
      }
    }
  };
  {
    if i == (Nat.Nata(Nat.Zero_nat{})) {
      q, m := x1.(List.Cons[a]);
      if m {
        xa, p := List.Cons_dest(q);
        q, m := p.(List.Cons[a]);
        if m {
          vb, vaa := List.Cons_dest(q);
          return DelListHead[a](List.Lista[a](List.Cons[a]{xa, List.Lista[a](List.Cons[a]{vb, vaa})}));
        }
      }
    }
  };
  {
    q, m := i.(Nat.Suc);
    if m {
      ib := Nat.Suc_dest(q);
      q, m := x1.(List.Cons[a]);
      if m {
        xa, p := List.Cons_dest(q);
        q, m := p.(List.Cons[a]);
        if m {
          vb, vaa := List.Cons_dest(q);
          return List.Lista[a](List.Cons[a]{xa, DelListIa[a](ib, List.Lista[a](List.Cons[a]{vb, vaa}))});
        }
      }
    }
  };
  panic("match failed");
}
