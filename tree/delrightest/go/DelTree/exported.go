package DelTree

import (
  . "isabelle/exported/Tree"
)


func DelRightest[a any] (x0 Tree[a]) Tree[a] {
  {
    q, m := x0.(Node[a]);
    if m {
      lefta, _, c := Node_dest(q);
      if c == (Tree[a](Tip[a]{})) {
        return lefta;
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      lefta, xa, p := Node_dest(q);
      q, m := p.(Node[a]);
      if m {
        vc, vaa, vba := Node_dest(q);
        return Tree[a](Node[a]{lefta, xa, DelRightest[a](Tree[a](Node[a]{vc, vaa, vba}))});
      }
    }
  };
  {
    if x0 == (Tree[a](Tip[a]{})) {
      return Tree[a](Tip[a]{});
    }
  };
  panic("match failed");
}


