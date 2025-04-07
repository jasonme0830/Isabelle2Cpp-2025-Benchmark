package AddListHead

import (
  "isabelle/exported/List"
)

func AddListHeada[a any] (aa a, xs List.Lista[a]) List.Lista[a] {
  return List.Lista[a](List.Cons[a]{aa, xs});
}
