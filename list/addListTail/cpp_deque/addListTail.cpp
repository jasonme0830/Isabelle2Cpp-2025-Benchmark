#include <iostream>
#include <fstream>
#include <vector>
#include "addListTail.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: ./main <size> <target>\n"; 
        exit(1);
    }
    uint64_t len = strtol(argv[1],NULL,10);
    std::cout << "len: " << len << std::endl;

    std::deque<int> newList;
    for (size_t i = len; i > 0; i--) {
        newList = AddListTail(int(i), newList);
    }

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    newList = AddListTail(0, newList);
    timespec_get(&end, TIME_UTC);
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    
    // 输出结果
    std::cout <<"  Time: " << elapsed <<" ns"<<std::endl;
    // for(int i=0; i<newList.size(); i++){
    //     std::cout << newList[i] << " ";
    // }
    // std::cout << std::endl;

    return 0;
}