package InsertTree

import (
  "isabelle/exported/Orderings"
  . "isabelle/exported/Tree"
)




func Inserttree[a any] (a_ Orderings.Ord[a], aa a, x1 Tree[a]) Tree[a] {
  {
    ac := aa;
    if x1 == (Tree[a](Tip[a]{})) {
      return Tree[a](Node[a]{Tree[a](Tip[a]{}), ac, Tree[a](Tip[a]{})});
    }
  };
  {
    ac := aa;
    q, m := x1.(Node[a]);
    if m {
      lefta, xa, righta := Node_dest(q);
      target := a_.Less_eq(ac, xa);
      {
        if target == (true) {
          return Tree[a](Node[a]{Inserttree[a](a_, ac, lefta), xa, righta});
        }
      };
      {
        if target == (false) {
          return Tree[a](Node[a]{lefta, xa, Inserttree[a](a_, ac, righta)});
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}
