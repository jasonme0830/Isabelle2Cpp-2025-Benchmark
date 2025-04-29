package ChangeTree

import (
  "isabelle/exported/HOL"
  . "isabelle/exported/Tree"
  "isabelle/exported/Orderings"
)


func Changetree[a any] (a1_ HOL.Equal[a], a2_ Orderings.Ord[a], aa a, b a, x2 Tree[a]) Tree[a] {
  {
    if x2 == (Tree[a](Tip[a]{})) {
      return Tree[a](Tip[a]{});
    }
  };
  {
    ac := aa;
    bb := b;
    q, m := x2.(Node[a]);
    if m {
      lefta, xa, righta := Node_dest(q);
      target := HOL.Eq[a](a1_, ac, xa);
      {
        if target == (true) {
          return Tree[a](Node[a]{lefta, bb, righta});
        }
      };
      {
        if target == (false) {
          targeu := a2_.Less(ac, xa);
          {
            if targeu == (true) {
              return Tree[a](Node[a]{Changetree[a](a1_, a2_, ac, bb, lefta), xa, righta});
            }
          };
          {
            if targeu == (false) {
              return Tree[a](Node[a]{lefta, xa, Changetree[a](a1_, a2_, ac, bb, righta)});
            }
          };
          panic("match failed");
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}
