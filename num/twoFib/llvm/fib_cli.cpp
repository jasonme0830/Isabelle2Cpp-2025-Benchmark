#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fib.h"


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>\n";
        return 1;
    }

    // 将输入参数转换为int64_t
    int64_t input = std::atoll(argv[1]);

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    
    // 调用LLVM函数
    int64_t result = fib(input);
    timespec_get(&end, TIME_UTC);
    double elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    
    // 输出结果
    std::cout << "Fib(" << input << ") = " << result << "  Time: " << elapsed <<"ns"<<std::endl;
    return 0;
}