package ModifyValue

import (
  "isabelle/exported/HOL"
  "isabelle/exported/List"
)

func ModifyValuea[a any] (a_ HOL.Equal[a], aa a, b a, x2 List.Lista[a]) List.Lista[a] {
  {
    if x2 == (List.Lista[a](List.Nil[a]{})) {
      return List.Lista[a](List.Nil[a]{});
    }
  };
  {
    ac := aa;
    bb := b;
    q, m := x2.(List.Cons[a]);
    if m {
      xa, xsa := List.Cons_dest(q);
      target := HOL.Eq[a](a_, xa, ac);
      {
        if target == (true) {
          return List.Lista[a](List.Cons[a]{bb, ModifyValuea[a](a_, ac, bb, xsa)});
        }
      };
      {
        if target == (false) {
          return List.Lista[a](List.Cons[a]{xa, ModifyValuea[a](a_, ac, bb, xsa)});
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}
