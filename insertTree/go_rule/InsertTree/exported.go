package InsertTree

import (
  // "isabelle/exported/HOL"
  "isabelle/exported/Orderings"
)

// sum type which can be Tip, Node
type Tree[a any] any;
type Tip[a any] struct {
};
type Node[a any] struct {
  A Tree[a];
  Aa a;
  Ab Tree[a];
};

func Node_dest[a any](p Node[a])(Tree[a], a, Tree[a]) {
  return p.A, p.Aa, p.Ab
}

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
