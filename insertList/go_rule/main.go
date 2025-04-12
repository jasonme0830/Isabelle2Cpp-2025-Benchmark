package main

import (
	"fmt"
	"time"
	"bufio"
	"os"
	"strconv"
	. "isabelle/exported/List"
	. "isabelle/exported/Orderings"
	. "isabelle/exported/InsertList"
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

	// 打开文件进行读取
	file, err := os.Open("../ArandomNum/random_numbers.txt")
	if err != nil {
		fmt.Println("open file error:", err)
		return
	}
	defer file.Close()
 
	var numbers []int
	scanner := bufio.NewScanner(file)
 
	// 从文件中读取指定数量的整数并存储到切片中
	for i := 0; i < num && scanner.Scan(); i++ {
		// 将每一行转换为整数
		number, err := strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Println("无法将行转换为整数:", err)
			continue
		}
		numbers = append(numbers, number)
	}
	// 检查扫描过程中是否有错误
	if err := scanner.Err(); err != nil {
		fmt.Println("read file error:", err)
		return
	}
	// print random numbers list
	// fmt.Println("random numbers list:")
	// for _, number := range numbers {
	// 	fmt.Print(number, " ")
	// }
	// fmt.Println()

	// TODO:fix the use of func "Less_eq" in the body of Insert
	intLess := Ord[int]{
		Less_eq: func(a, b int) bool {
			return a <= b
		},
		Less: func(a, b int) bool {
			return a < b
		},
	}

	newList := Lista[int](Nil[int]{})
	if tar == 0 {
		
		startNano := time.Now().UnixNano() // 获取纳秒时间戳
		for i:=0; i<len(numbers); i++ {
			newList = InsertLista(intLess, numbers[i], newList)
		}
		endNano := time.Now().UnixNano()
		elapsedNano := endNano - startNano

		fmt.Println(" time: ", elapsedNano," ns")
	} else {
		for i:=0; i<len(numbers); i++ {
			newList = InsertLista(intLess, numbers[i], newList)
		}
		startNano := time.Now().UnixNano() // 获取纳秒时间戳
		newList = InsertLista(intLess, tar, newList)
		endNano := time.Now().UnixNano()
		elapsedNano := endNano - startNano
		
		fmt.Println(" time: ", elapsedNano," ns")

	}

	// printHelper(newList)
}

