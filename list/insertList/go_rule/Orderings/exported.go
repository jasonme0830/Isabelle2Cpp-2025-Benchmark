package Orderings

import (
)

type Ord[a any] struct {
  Less_eq func(a, a) bool
  Less func(a, a) bool
}
