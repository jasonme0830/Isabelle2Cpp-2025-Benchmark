package AddListTail

import (
  "isabelle/exported/List"
)

func AddListTaila[a any] (aa a, x1 List.Lista[a]) List.Lista[a] {
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
      return List.Lista[a](List.Cons[a]{xa, AddListTaila[a](ac, xsa)});
    }
  };
  panic("match failed");
}
