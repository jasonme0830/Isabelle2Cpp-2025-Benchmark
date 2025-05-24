package AddListI

import (
  "isabelle/exported/Nat"
  "isabelle/exported/List"
)

func AddListHead[a any] (aa a, xs List.Lista[a]) List.Lista[a] {
  return List.Lista[a](List.Cons[a]{aa, xs});
}

func AddListIa[a any] (i Nat.Nata, aa a, x2 List.Lista[a]) List.Lista[a] {
  {
    ac := aa;
    if x2 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Cons[a]{ac, List.Lista[a](List.Nil[a]{})});
    }
  };
  {
    if i == (Nat.Nata(Nat.Zero_nat{})) {
      ac := aa;
      q, m := x2.(List.Cons[a]);
      if m {
        xa, xsa := List.Cons_dest(q);
        return AddListHead[a](ac, List.Lista[a](List.Cons[a]{xa, xsa}));
      }
    }
  };
  {
    q, m := i.(Nat.Suc);
    if m {
      ib := Nat.Suc_dest(q);
      ac := aa;
      q, m := x2.(List.Cons[a]);
      if m {
        xa, xsa := List.Cons_dest(q);
        return List.Lista[a](List.Cons[a]{xa, AddListIa[a](ib, ac, xsa)});
      }
    }
  };
  panic("match failed");
}
