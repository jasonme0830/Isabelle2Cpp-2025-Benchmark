#include <iostream>
#include <fstream>
#include <vector>
#include "deltreeroot.h"


void
// print_tree(const tree<int> &tree)
print_tree(tree<int> tree)
{
    if(tree.is_Tip()) return;

    std::cout<<"(";
    print_tree(tree.as_Node().p1());
    std::cout<<")";

    std::cout<<" "<<tree.as_Node().p2()<<" ";

    std::cout<<"(";
    print_tree(tree.as_Node().p3());
    std::cout<<")";
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "usage: ./main <size> <target>\n"; 
        exit(1);
    }
    uint64_t len = strtol(argv[1],NULL,10);
    uint64_t tar = strtol(argv[2],NULL,10);
    std::cout << "len: " << len << "   tar: " << tar << std::endl;

    // std::ifstream inFile("../ArandomNum/random_numbers.txt");
    // if (!inFile) {
    //     std::cerr << "open file error!" << std::endl;
    //     return 1;
    // }

    // //read txt
    // std::vector<int> numbers;
    // int number;
    // // 从文件中读取整数并存储到vector中
    // for(int i=0; i<len; i++){
    //     inFile >> number;
    //     numbers.push_back(number);
    // }
    // inFile.close();

    std::vector<int> numbers;
    numbers.push_back(0);
    for(int i=1; i<len; i++){
        numbers.push_back(i);
        numbers.push_back(i*-1);
    }

    // 输出读取的整数
    // std::cout << "从文件中读取的整数:" << std::endl;
    // for (size_t i = 0; i < numbers.size(); ++i) {
    //     std::cout << numbers[i] << " ";
    // }
    // std::cout << std::endl;

    tree<int> copy_tree = tree<int>::Tip();
    for (size_t i = 0; i < numbers.size(); ++i) {
        copy_tree = inserttree(numbers[i], std::move(copy_tree));
    }
    // print_tree(copy_tree);
    // std::cout << std::endl;

    struct timespec start, end;
    tree<int> res, temp_move;

    if(tar == 0){
        timespec_get(&start, TIME_UTC);
        res = deltreeroot(copy_tree);
        // res = copy_tree.as_Node().p1();
        // const auto& temp = copy_tree.as_Node().p1();
        // res = temp.self();
        // res = copy_tree.as_Node().p3();
        // res = copy_tree.self();
        timespec_get(&end, TIME_UTC);
    }else if(tar == 1){
        timespec_get(&start, TIME_UTC);
        // res = deltreeroot(std::move(copy_tree));

        // const auto& left = copy_tree.as_Node().p1();
        // const auto& mid = copy_tree.as_Node().p2();
        // const auto& right = copy_tree.as_Node().p3();

        auto left = copy_tree.as_Node().p1();
        auto mid = copy_tree.as_Node().p2();
        auto right = copy_tree.as_Node().p3();
        res = tree<int>::Node(left, mid, right);
        // const tree<int>& temp = tree<int>::Node(left, mid, right);
        timespec_get(&end, TIME_UTC);
    }else{
        timespec_get(&start, TIME_UTC);
        // res = deltreeroot(copy_tree);
        // res = copy_tree.self();
        // auto temp = copy_tree.self();
        // temp_move = std::move(copy_tree);
        const tree<int>& temp = copy_tree.as_Node().p1();
        res = temp;
        // temp_move = copy_tree.as_Node().p3();
        // auto temp = copy_tree.as_Node();
        timespec_get(&end, TIME_UTC);
    }

    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    // print_tree(res);
    // std::cout << std::endl;
    // print_tree(temp_move);
    // std::cout << std::endl;
    
    // 输出结果
    std::cout <<"   Time: " << elapsed <<" ns"<<std::endl;
    return 0;
}