package TwoFib

import (
  "isabelle/exported/Nat"
  "isabelle/exported/Num"
)

func Two_fib (x0 Nat.Nata) Nat.Nata {
  {
    if x0 == (Nat.Nata(Nat.Zero_nat{})) {
      return Nat.Nata(Nat.Zero_nat{});
    }
  };
  {
    q, m := x0.(Nat.Suc);
    if m {
      c := Nat.Suc_dest(q);
      if c == (Nat.Nata(Nat.Zero_nat{})) {
        return Nat.One_nat();
      }
    }
  };
  {
    q, m := x0.(Nat.Suc);
    if m {
      p := Nat.Suc_dest(q);
      q, m := p.(Nat.Suc);
      if m {
        vaa := Nat.Suc_dest(q);
        return Nat.Plus_nat(Two_fib(Nat.Minus_nat(Nat.Nata(Nat.Suc{Nat.Nata(Nat.Suc{vaa})}), Nat.One_nat())), Two_fib(Nat.Minus_nat(Nat.Nata(Nat.Suc{Nat.Nata(Nat.Suc{vaa})}), Num.Nat_of_num(Num.Numa(Num.Bit0{Num.Numa(Num.One{})})))));
      }
    }
  };
  panic("match failed");
}
