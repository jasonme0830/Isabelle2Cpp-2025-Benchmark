package Reverse

import (
  "isabelle/exported/List"
)

func App[a any] (x0 List.Lista[a], as List.Lista[a]) List.Lista[a] {
  {
    if x0 == (List.Lista[a](List.Nil[a]{})) {
      asb := as;
      return asb;
    }
  };
  {
    q, m := x0.(List.Cons[a]);
    if m {
      ab, asb := List.Cons_dest(q);
      bsa := as;
      return List.Lista[a](List.Cons[a]{ab, App[a](asb, bsa)});
    }
  };
  panic("match failed");
}

func Reversea[a any] (x0 List.Lista[a]) List.Lista[a] {
  {
    if x0 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Nil[a]{});
    }
  };
  {
    q, m := x0.(List.Cons[a]);
    if m {
      ab, asa := List.Cons_dest(q);
      return App[a](Reversea[a](asa), List.Lista[a](List.Cons[a]{ab, List.Lista[a](List.Nil[a]{})}));
    }
  };
  panic("match failed");
}
