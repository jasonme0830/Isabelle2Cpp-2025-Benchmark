all: fib


fib: fib_cli.cpp fib.ll
	llvm-as -disable-output fib.ll
#	llc fib.ll -filetype=obj -o fib.o
	clang++ -Wall -O3 fib_cli.cpp fib.ll -o fib