package InsertList

import (
  "isabelle/exported/List"
  "isabelle/exported/Orderings"
)

func InsertLista[a any] (a_ Orderings.Ord[a], aa a, x1 List.Lista[a]) List.Lista[a] {
  {
    ac := aa;
    if x1 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Cons[a]{ac, List.Lista[a](List.Nil[a]{})});
    }
  };
  {
    ac := aa;
    q, m := x1.(List.Cons[a]);
    if m {
      xa, xsa := List.Cons_dest(q);
      target := a_.Less_eq(ac, xa);
      {
        if target == (true) {
          return List.Lista[a](List.Cons[a]{ac, List.Lista[a](List.Cons[a]{xa, xsa})});
        }
      };
      {
        if target == (false) {
          return List.Lista[a](List.Cons[a]{xa, InsertLista[a](a_, ac, xsa)});
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}
