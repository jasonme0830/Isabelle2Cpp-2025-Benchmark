package InsertSort

import (
  "isabelle/exported/List"
  "isabelle/exported/Orderings"
)

func Insert[a any] (a_ Orderings.Ord[a], aa a, x1 List.Lista[a]) List.Lista[a] {
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
          return List.Lista[a](List.Cons[a]{xa, Insert[a](a_, ac, xsa)});
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}

func InsertSortPart[a any] (a_ Orderings.Ord[a], x0 List.Lista[a], ys List.Lista[a]) List.Lista[a] {
  {
    if x0 == (List.Lista[a](List.Nil[a]{})) {
      ysb := ys;
      return ysb;
    }
  };
  {
    q, m := x0.(List.Cons[a]);
    if m {
      xa, xsa := List.Cons_dest(q);
      ysb := ys;
      return InsertSortPart[a](a_, xsa, Insert[a](a_, xa, ysb));
    }
  };
  panic("match failed");
}

func InsertSorta[a any] (a_ Orderings.Ord[a], xs List.Lista[a]) List.Lista[a] {
  return InsertSortPart[a](a_, xs, List.Lista[a](List.Nil[a]{}));
}
