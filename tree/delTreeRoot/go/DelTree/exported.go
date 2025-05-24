package DelTree

import (
  "isabelle/exported/HOL"
  // "isabelle/exported/Orderings"
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

func Rightest[a any] (x0 Tree[a]) a {
  {
    q, m := x0.(Node[a]);
    if m {
      _, xa, c := Node_dest(q);
      if c == (Tree[a](Tip[a]{})) {
        return xa;
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      _, _, p := Node_dest(q);
      q, m := p.(Node[a]);
      if m {
        vc, vaa, vba := Node_dest(q);
        return Rightest[a](Tree[a](Node[a]{vc, vaa, vba}));
      }
    }
  };
  panic("match failed");
}

// func Deltreeroot[a any] (a_ HOL.Equal[a], x0 Tree[a]) Tree[a] {
//   {
//     if x0 == (Tree[a](Tip[a]{})) {
//       return Tree[a](Tip[a]{});
//     }
//   };
//   {
//     q, m := x0.(Node[a]);
//     if m {
//       lefta, _, righta := Node_dest(q);
//       target := Equal_tree[a](a_, righta, Tree[a](Tip[a]{}));
//       {
//         if target == (true) {
//           return lefta;
//         }
//       };
//       {
//         if target == (false) {
//           targeu := Equal_tree[a](a_, lefta, Tree[a](Tip[a]{}));
//           {
//             if targeu == (true) {
//               return righta;
//             }
//           };
//           {
//             if targeu == (false) {
//               return Tree[a](Node[a]{DelRightest[a](lefta), Rightest[a](lefta), righta});
//             }
//           };
//           panic("match failed");
//         }
//       };
//       panic("match failed");
//     }
//   };
//   panic("match failed");
// }

func Deltreeroot[a any] (x0 Tree[a]) Tree[a] {
  {
    if x0 == (Tree[a](Tip[a]{})) {
      return Tree[a](Tip[a]{});
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      d, _, c := Node_dest(q);
      if d == (Tree[a](Tip[a]{})) && c == (Tree[a](Tip[a]{})) {
        return Tree[a](Tip[a]{});
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      c, _, p := Node_dest(q);
      if c == (Tree[a](Tip[a]{})) {
        q, m := p.(Node[a]);
        if m {
          vc, vaa, vba := Node_dest(q);
          return Tree[a](Node[a]{vc, vaa, vba});
        }
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      p, _, c := Node_dest(q);
      if c == (Tree[a](Tip[a]{})) {
        q, m := p.(Node[a]);
        if m {
          vc, vaa, vba := Node_dest(q);
          return Tree[a](Node[a]{vc, vaa, vba});
        }
      }
    }
  };
  {
    q, m := x0.(Node[a]);
    if m {
      q, _, p := Node_dest(q);
      r, m := q.(Node[a]);
      if m {
        vf, vaa, vba := Node_dest(r);
        r, m := p.(Node[a]);
        if m {
          vca, vda, vea := Node_dest(r);
          return Tree[a](Node[a]{DelRightest[a](Tree[a](Node[a]{vf, vaa, vba})), Rightest[a](Tree[a](Node[a]{vf, vaa, vba})), Tree[a](Node[a]{vca, vda, vea})});
        }
      }
    }
  };
  panic("match failed");
}