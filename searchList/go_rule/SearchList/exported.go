package SearchList

import (
  "isabelle/exported/HOL"
  "isabelle/exported/List"
)

func SearchLista[a any] (a_ HOL.Equal[a], aa a, x1 List.Lista[a]) bool {
  {
    if x1 == (List.Lista[a](List.Nil[a]{})) {
      return false;
    }
  };
  {
    ac := aa;
    q, m := x1.(List.Cons[a]);
    if m {
      xa, xsa := List.Cons_dest(q);
      target := HOL.Eq[a](a_, ac, xa);
      {
        if target == (true) {
          return true;
        }
      };
      {
        if target == (false) {
          return SearchLista[a](a_, ac, xsa);
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}
