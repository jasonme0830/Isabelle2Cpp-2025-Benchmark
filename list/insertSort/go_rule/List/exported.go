package List

import (
)

// sum type which can be Nil, Cons
type Lista[a any] any;
type Nil[a any] struct {
};
type Cons[a any] struct {
  A a;
  Aa Lista[a];
};

func Cons_dest[a any](p Cons[a])(a, Lista[a]) {
  return p.A, p.Aa
}
