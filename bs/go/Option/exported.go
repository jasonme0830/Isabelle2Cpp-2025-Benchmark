package Option

import (
)

// sum type which can be None, Some
type Optiona[a any] any;
type None[a any] struct {
};
type Some[a any] struct {
  A a;
};

func Some_dest[a any](p Some[a])(a) {
  return p.A
}
