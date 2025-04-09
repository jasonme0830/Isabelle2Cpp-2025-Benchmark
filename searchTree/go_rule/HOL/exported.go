package HOL

import (
)

type Equal[a any] struct {
  Equala func(a, a) bool
}

func Eq[a any] (a_ Equal[a], aa a, b a) bool {
  return a_.Equala(aa, b);
}

