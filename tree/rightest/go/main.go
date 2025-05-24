package main

import (
	"fmt"
	"time"
	// "bufio"
	"os"
	"strconv"
	// . "isabelle/exported/HOL"
	. "isabelle/exported/Tree"
	. "isabelle/exported/Orderings"
    . "isabelle/exported/InsertTree"
	. "isabelle/exported/DelTree" 
)

// 定义一个辅助函数，用于判断一个 Tree 是否是 Tip 类型
func isTip[a any](t Tree[a]) bool {
	_, ok := t.(Tip[a])
	return ok
}
// 打印函数，递归打印二叉树
func printTree[a any](t Tree[a], indent string) {
	if isTip(t) {
		fmt.Print(indent + "Tip")
		return
	}
 
	// 类型断言为 Node
	node, ok := t.(Node[a])
	if !ok {
		fmt.Println("Invalid tree structure")
		return
	}

	// 打印左子树
	fmt.Print("(")
	printTree(node.A, indent+"")
	fmt.Print(")")
	// 打印当前节点
	fmt.Print(indent + fmt.Sprintf(" Node(%v) ", node.Aa))
	// 打印右子树
	fmt.Print("(")
	printTree(node.Ab, indent+"")
	fmt.Print(")")
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

	var numbers []int
	numbers = append(numbers, 0)
	for i:=1; i<num; i++{
		numbers = append(numbers, i)
		numbers = append(numbers, i*-1)
	}	
	// print random numbers list
	// fmt.Print("random numbers list:  ")
	// for _, number := range numbers {
	// 	fmt.Print(number, " ")
	// }
	// fmt.Println()

	// 实例化 Ord 结构体，例如用于比较整数
	// TODO:fix the use of func "Less_eq" in the body of Inserttree
	intLess := Ord[int]{
		Less_eq: func(a, b int) bool {
			return a <= b
		},
		Less: func(a, b int) bool {
			return a < b
		},
	}
	newTree := Inserttree(intLess, numbers[0], Tree[int](Tip[int]{}))
	for i:=1; i<len(numbers); i++{
		newTree = Inserttree(intLess, numbers[i], newTree)
	}
	// printTree(newTree, "")
	// fmt.Println()

	// 单次运行结果差异太多，多次运行取平均值
	const runs = 100
	var totalTime int64
	var res int
	
	for i:=0; i<runs; i++{
		start := time.Now()
		res = Rightest(newTree)
		totalTime += time.Since(start).Nanoseconds()
	}
	
	elapsedNano := totalTime / runs

	fmt.Println("res: ", res, "   time: ", elapsedNano," ns")
}

