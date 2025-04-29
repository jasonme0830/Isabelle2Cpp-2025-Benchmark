package main

import (
	"fmt"
	"time"
	// "bufio"
	"os"
	"strconv"
	. "isabelle/exported/HOL"
	. "isabelle/exported/List"
	. "isabelle/exported/ModifyValue"
)

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


	//实例化 Equal 结构体，例如用于比较整数
	intEqual := Equal[int]{
		Equala: func(a, b int) bool {
			return a == b
		},
	}

	newList := Lista[int](Nil[int]{})
	for i:=0; i<num; i++ {
		newList = Lista[int](Cons[int]{i, newList})
	}
	// printHelper(newList)

	startNano := time.Now().UnixNano() // 获取纳秒时间戳
	newList = ModifyValuea(intEqual, 1, tar, newList)
	endNano := time.Now().UnixNano()
	elapsedNano := endNano - startNano

	// printHelper(res)
	
	fmt.Println(" time: ", elapsedNano," ns")

	
}

