#include <iostream>
#include <fstream>
#include <vector>
#include "cons.h"

void print_list(const slist<int> &argu){
    if(!argu.is_sNil()){
      std::cout<<argu.as_sCons().p1()<<" ";
      print_list(argu.as_sCons().p2());
    }
    if(argu.is_sNil()){
        std::cout << "nil" << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: ./main <size> <target>\n"; 
        exit(1);
    }
    uint64_t len = strtol(argv[1],NULL,10);
    std::cout << "len: " << len << std::endl;

    slist<int> newList = slist<int>::sNil();
    for(int i=len-1; i>0; i--){
        // newList = AddListHead(i, newList);
        newList = slist<int>::sCons(i, std::move(newList));
    }
    // print_list(newList);

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
        slist<int> copyList = slist<int>::sCons(0, newList);
        // slist<int> copyList = slist<int>::sCons(0, std::move(newList));
    timespec_get(&end, TIME_UTC);
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    
    // 输出结果
    std::cout <<"Cons  Time: " << elapsed <<" ns"<<std::endl;
    // newList = slist<int>::sNil();
    // print_list(newList);
    // print_list(copyList);


    return 0;
}