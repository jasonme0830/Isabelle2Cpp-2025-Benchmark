package main

import (
	"fmt"
	"time"
	"os"
	"strconv"
	. "isabelle/exported/List"
    . "isabelle/exported/Nat" // 导入模块中的包
	. "isabelle/exported/Option"
	"isabelle/exported/AddListHead"
	// . "isabelle/exported/Product_Type"
	// "isabelle/exported/Euclidean_Rings"
	. "isabelle/exported/BinarySearch"
)

// IntToNat 将整数转换为Nata类型
func IntToNat(n int) Nata {
    if n < 0 {
        panic("负数不能转换为自然数")
    }
    if n == 0 {
        return Zero_nat{}
    }
    return Suc{A: IntToNat(n - 1)}
}
 
// NatToInt 将Nata类型转换为整数
func NatToInt(n Nata) int {
    switch v := n.(type) {
    case Zero_nat:
        return 0
    case Suc:
        return 1 + NatToInt(v.A)
    default:
        panic("无效的Nata类型")
    }
}

// 打印Optiona值的函数
func PrintOption[A any](opt Optiona[A]) {
    switch v := any(opt).(type) {
    case None[A]:
        fmt.Println("None")
    case Some[A]:
        fmt.Printf("Some(%v)", NatToInt(v.A))
    default:
        fmt.Printf("Invalid Optiona type: %T\n", opt)
    }
}

// 打印链表，伴随nat转换
func printHelper[a any](list Lista[a]) {
    switch v := list.(type) {
    case Nil[a]:
        fmt.Printf("Nil\n")
        return // 空链表直接返回
    case Cons[a]:
        fmt.Printf("%v -> ", NatToInt(v.A))
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

	xs := Nil[Nata]{}
	one := IntToNat(num)
	newList := AddListHead.AddListHeada[Nata](one, xs)
	for i:=num-1; i>0; i--{
		temp := IntToNat(i)
		newList = AddListHead.AddListHeada[Nata](temp, newList)
	}
	printHelper(newList)

	//设置一个查找目标
	target := IntToNat(tar)

	startNano := time.Now().UnixNano() // 获取纳秒时间戳
	res := Bs(target, newList)
	endNano := time.Now().UnixNano()
	elapsedNano := endNano - startNano

	PrintOption(res)
	fmt.Println("   time: ", elapsedNano,"ns")
}

