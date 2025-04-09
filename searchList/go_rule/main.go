package main

import (
	"fmt"
	"time"
	"os"
	"strconv"
	. "isabelle/exported/HOL"
	. "isabelle/exported/List"
    "isabelle/exported/AddListHead" // 导入模块中的包
	"isabelle/exported/SearchList"

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
	// 获取命令行参数
	args := os.Args[1:]
 
	// 检查是否提供了参数
	if len(args) < 1 {
		fmt.Println("错误：请提供一个整数参数")
		fmt.Println("用法：程序名 <整数>")
		os.Exit(1)
	}
 
	// 尝试转换参数为整数
	num, err := strconv.Atoi(args[0])
	tar, eoo := strconv.Atoi(args[1])
	if (err != nil)||(eoo != nil) {
		fmt.Printf("错误：无效的整数参数 '%s'\n", args[0])
		os.Exit(1)
	}
	fmt.Println("num: ", num, "   target: ", tar)

	xs := Nil[int]{}
	newList := AddListHead.AddListHeada[int](num, xs)
	for i:=num-1; i>0; i--{
		newList = AddListHead.AddListHeada[int](i, newList)
	}
	printHelper(newList)

	// 实例化 Equal 结构体，例如用于比较整数
	intEqual := Equal[int]{
		Equala: func(a, b int) bool {
			return a == b
		},
	}

	startNano := time.Now().UnixNano() // 获取纳秒时间戳
	res := SearchList.SearchLista(intEqual, tar, newList)
	endNano := time.Now().UnixNano()
	elapsedNano := endNano - startNano

	
	fmt.Println("res: ", res, "  time: ", elapsedNano," ns")
}

