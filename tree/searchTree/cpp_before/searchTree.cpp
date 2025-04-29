#include <iostream>
#include <fstream>
#include <vector>
#include "searchTree.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "usage: ./main <size> <target>\n"; 
        exit(1);
    }
    uint64_t len = strtol(argv[1],NULL,10);
    uint64_t tar = strtol(argv[2],NULL,10);
    std::cout << "len: " << len << "   tar: " << tar << std::endl;

    std::ifstream inFile("../ArandomNum/random_numbers.txt");
    if (!inFile) {
        std::cerr << "open file error!" << std::endl;
        return 1;
    }

    //read txt
    std::vector<int> numbers;
    int number;
    // 从文件中读取整数并存储到vector中
    for(int i=0; i<len; i++){
        inFile >> number;
        numbers.push_back(number);
    }
    inFile.close();

    // 输出读取的整数
    // std::cout << "从文件中读取的整数:" << std::endl;
    // for (size_t i = 0; i < numbers.size(); ++i) {
    //     std::cout << numbers[i] << " ";
    // }
    // std::cout << std::endl;

    tree<int> copy_tree = tree<int>::Tip();
    for (size_t i = 0; i < numbers.size(); ++i) {
        copy_tree = inserttree(numbers[i], copy_tree);
    }

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    bool res = searchtree1(int(tar), copy_tree);
    timespec_get(&end, TIME_UTC);
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    
    // 输出结果
    std::cout <<"res: " << res << "  Time: " << elapsed <<" ns"<<std::endl;

    return 0;
}