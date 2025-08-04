package DelListTail

import (
  "isabelle/exported/List"
)

func DelListTaila[a any] (x0 List.Lista[a]) List.Lista[a] {
  {
    if x0 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Nil[a]{});
    }
  };
  {
    q, m := x0.(List.Cons[a]);
    if m {
      _, c := List.Cons_dest(q);
      if c == (List.Lista[a](List.Nil[a]{})) {
        return List.Lista[a](List.Nil[a]{});
      }
    }
  };
  {
    q, m := x0.(List.Cons[a]);
    if m {
      xa, p := List.Cons_dest(q);
      q, m := p.(List.Cons[a]);
      if m {
        vb, vaa := List.Cons_dest(q);
        return List.Lista[a](List.Cons[a]{xa, DelListTaila[a](List.Lista[a](List.Cons[a]{vb, vaa}))});
      }
    }
  };
  panic("match failed");
}
