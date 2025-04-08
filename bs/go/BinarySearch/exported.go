package BinarySearch

import (
  // "isabelle/exported/HOL"
  "isabelle/exported/Nat"
  "isabelle/exported/Num"
  "isabelle/exported/List"
  "isabelle/exported/Option"
  "isabelle/exported/Euclidean_Rings"
)

func Bs (x Nat.Nata, xa1 List.Lista[Nat.Nata]) Option.Optiona[Nat.Nata] {
  {
    if xa1 == (List.Lista[Nat.Nata](List.Nil[Nat.Nata]{})) {
      return Option.Optiona[Nat.Nata](Option.None[Nat.Nata]{});
    }
  };
  {
    xb := x;
    q, m := xa1.(List.Cons[Nat.Nata]);
    if m {
      ya, c := List.Cons_dest(q);
      if c == (List.Lista[Nat.Nata](List.Nil[Nat.Nata]{})) {
        target := Nat.Equal_nat(xb, ya);
        {
          if target == (true) {
            return Option.Optiona[Nat.Nata](Option.Some[Nat.Nata]{Nat.Nata(Nat.Zero_nat{})});
          }
        };
        {
          if target == (false) {
            return Option.Optiona[Nat.Nata](Option.None[Nat.Nata]{});
          }
        };
        panic("match failed");
      }
    }
  };
  {
    xb := x;
    q, m := xa1.(List.Cons[Nat.Nata]);
    if m {
      va, p := List.Cons_dest(q);
      q, m := p.(List.Cons[Nat.Nata]);
      if m {
        vba, vca := List.Cons_dest(q);
        m := Euclidean_Rings.Divide_nat((List.Size_list[Nat.Nata]() (List.Lista[Nat.Nata](List.Cons[Nat.Nata]{va, List.Lista[Nat.Nata](List.Cons[Nat.Nata]{vba, vca})}))), Num.Nat_of_num(Num.Numa(Num.Bit0{Num.Numa(Num.One{})})));
        y := List.Nth[Nat.Nata](List.Lista[Nat.Nata](List.Cons[Nat.Nata]{va, List.Lista[Nat.Nata](List.Cons[Nat.Nata]{vba, vca})}), m);
        target := Nat.Equal_nat(y, xb);
        {
          if target == (true) {
            return Option.Optiona[Nat.Nata](Option.Some[Nat.Nata]{m});
          }
        };
        {
          if target == (false) {
            targeu := Nat.Less_nat(y, xb);
            {
              if targeu == (true) {
                targev := Bs(xb, List.Drop[Nat.Nata](Nat.Plus_nat(m, Nat.One_nat()), List.Lista[Nat.Nata](List.Cons[Nat.Nata]{va, List.Lista[Nat.Nata](List.Cons[Nat.Nata]{vba, vca})})));
                {
                  if targev == (Option.Optiona[Nat.Nata](Option.None[Nat.Nata]{})) {
                    return Option.Optiona[Nat.Nata](Option.None[Nat.Nata]{});
                  }
                };
                {
                  r, q := targev.(Option.Some[Nat.Nata]);
                  if q {
                    na := Option.Some_dest(r);
                    return Option.Optiona[Nat.Nata](Option.Some[Nat.Nata]{Nat.Plus_nat(Nat.Plus_nat(m, na), Nat.One_nat())});
                  }
                };
                panic("match failed");
              }
            };
            {
              if targeu == (false) {
                return Bs(xb, List.Take[Nat.Nata](m, List.Lista[Nat.Nata](List.Cons[Nat.Nata]{va, List.Lista[Nat.Nata](List.Cons[Nat.Nata]{vba, vca})})));
              }
            };
            panic("match failed");
          }
        };
        panic("match failed");
      }
    }
  };
  panic("match failed");
}
