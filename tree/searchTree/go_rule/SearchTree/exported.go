package SearchTree

import (
  "isabelle/exported/HOL"
  . "isabelle/exported/Tree"
)


func Searchtree1[a any] (a_ HOL.Equal[a], aa a, x1 Tree[a]) bool {
  {
    if x1 == (Tree[a](Tip[a]{})) {
      return false;
    }
  };
  {
    ac := aa;
    q, m := x1.(Node[a]);
    if m {
      lefta, xa, righta := Node_dest(q);
      return HOL.Eq[a](a_, ac, xa) || (Searchtree1[a](a_, ac, lefta) || Searchtree1[a](a_, ac, righta));
    }
  };
  panic("match failed");
}
