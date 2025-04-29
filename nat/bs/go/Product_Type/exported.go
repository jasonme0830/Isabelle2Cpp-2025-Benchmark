package Product_Type

import (
)

type Prod[a, b any] struct {
  A a;
  Aa b;
};
func Pair_dest[a, b any](p Prod[a, b])(a, b) {
  return  p.A, p.Aa;
}

func Fst[a, b any] (x0 Prod[a, b]) a {
  {
    _ = x0;
    x1a, _ := Pair_dest(x0);
    return x1a;
  };
  panic("match failed");
}
