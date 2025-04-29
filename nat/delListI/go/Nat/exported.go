package Nat

import (
)

// sum type which can be Zero_nat, Suc
type Nata any;
type Zero_nat struct {
};
type Suc struct {
  A Nata;
};

func Suc_dest(p Suc)(Nata) {
  return p.A
}
