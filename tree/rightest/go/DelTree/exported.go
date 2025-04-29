package DelTree

import (
  "isabelle/exported/HOL"
  . "isabelle/exported/Tree"
)


func Equal_tree[a any] (a_ HOL.Equal[a], x0 Tree[a], x1 Tree[a]) bool {
  {
    if x0 == (Tree[a](Tip[a]{})) {
      _, m := x1.(Node[a]);
      if m {
        return false;
      }
    }
  };
  {
    _, m := x0.(Node[a]);
    if m {
      if x1 == (Tree[a](Tip[a]{})) {
        return false;
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      x21a, x22a, x23a := Node_dest(q);
      q, m := x1.(Node[a]);
      if m {
        y21a, y22a, y23a := Node_dest(q);
        return Equal_tree[a](a_, x21a, y21a) && (HOL.Eq[a](a_, x22a, y22a) && Equal_tree[a](a_, x23a, y23a));
      }
    }
  };
  {
    if x0 == (Tree[a](Tip[a]{})) {
      if x1 == (Tree[a](Tip[a]{})) {
        return true;
      }
    }
  };
  panic("match failed");
}


func Rightest[a any] (a_ HOL.Equal[a], x0 Tree[a]) a {
  {
    q, m := x0.(Node[a]);
    if m {
      _, xa, righta := Node_dest(q);
      target := Equal_tree[a](a_, righta, Tree[a](Tip[a]{}));
      {
        if target == (true) {
          return xa;
        }
      };
      {
        if target == (false) {
          return Rightest[a](a_, righta);
        }
      };
      panic("match failed");
    }
  };
  panic("match failed");
}


