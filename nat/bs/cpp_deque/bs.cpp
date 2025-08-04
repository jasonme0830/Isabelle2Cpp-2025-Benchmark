#include "bs.h"



int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "usage: ./bs <size> <target>\n"; 
        exit(1);
    }
    
    uint64_t len = strtol(argv[1],NULL,10);
    // uint64_t tar = strtol(argv[2],NULL,10);
  
    std::deque<std::uint64_t> array;
    for (std::uint64_t i=1; i<=len; ++i) {
        array.push_back(i*5);
    }

    // for(auto pos=array.begin(); pos!=array.end(); pos++){
    //     std::cout << *pos << " ";
    // }
    // std::cout << std::endl;

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    for(int i=0; i<5*int(len); i+=2){
        bs(i, array);  
    }
    timespec_get(&end, TIME_UTC);
    double elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    
    // 输出结果
    // std::cout <<"res: " << res.value() << "  Time: " << elapsed <<" ns"<<std::endl;
    std::cout << "  Time: " << int(elapsed/1000) <<"  us"<<std::endl;

    
  }