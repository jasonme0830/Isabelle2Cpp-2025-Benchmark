package main

import (
	"fmt"
	. "isabelle/exported/List"
    "isabelle/exported/AddListHead" // 导入模块中的包
)

// 
func printHelper[a any](list Lista[a]) {
    switch v := list.(type) {
    case Nil[a]:
        fmt.Printf("Nil\n")
        return // 空链表直接返回
    case Cons[a]:
        fmt.Printf("%v -> ", v.A)
        printHelper(v.Aa)
    default:
        panic(fmt.Sprintf("未知链表类型: %T", list))
    }
}

func main() {
	xs := Nil[int]{};
	newList := AddListHead.AddListHeada[int](9, xs)
	printHelper(newList)
}

