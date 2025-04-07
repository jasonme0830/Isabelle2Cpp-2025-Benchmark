package main

import (
	"fmt"
	"time"
	"os"
	"strconv"
    . "isabelle/exported/Nat"  // 导入自定义包
    // "isabelle/exported/Num"
	"isabelle/exported/TwoFib"
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

func main() {
	// 获取命令行参数
	args := os.Args[1:]
	var one Nata;
	if num, err := strconv.Atoi(args[0]); err == nil {
		// fmt.Printf("整数: %d\n", num)
		one = IntToNat(num)
	} 

	startNano := time.Now().UnixNano() // 获取纳秒时间戳
	res := TwoFib.Two_fib(one)
	endNano := time.Now().UnixNano()
	elapsedNano := endNano - startNano

	data := NatToInt(res)
	fmt.Println("fib: ", data, " time: ", elapsedNano,"ns")
}