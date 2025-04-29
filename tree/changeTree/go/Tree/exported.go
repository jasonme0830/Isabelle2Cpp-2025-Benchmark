package Tree

// sum type which can be Tip, Node
type Tree[a any] any;
type Tip[a any] struct {
};
type Node[a any] struct {
  A Tree[a];
  Aa a;
  Ab Tree[a];
};

func Node_dest[a any](p Node[a])(Tree[a], a, Tree[a]) {
  return p.A, p.Aa, p.Ab
}