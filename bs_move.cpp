#include "bs.h"

std::optional<std::uint64_t> bs(std::uint64_t arg1, std::deque<std::uint64_t> arg2) {
    // bs x [] = None
    if (arg2.empty()) {
        return std::optional<std::uint64_t>();
    }

    // bs x [y] = If (x = y) (Some sZero) None
    if (arg2.size() == 1) {
        auto x = std::move(arg1);
        auto y = arg2[0];
        std::optional<std::uint64_t> temp0;
        if (x == y) {
            temp0 = std::make_optional<std::uint64_t>(0);
        } else {
            temp0 = std::optional<std::uint64_t>();
        }
        return temp0;
    }

    // bs x ys = (let m = (length ys) div 2 in ...
    auto x = std::move(arg1);
    auto ys = std::move(arg2);
    auto temp0 = ys.size() / 2;
    auto m = temp0;
    auto temp2 = ys;
    auto temp1 = temp2[m];
    auto y = temp1;
    std::optional<std::uint64_t> temp3;
    if (y == x) {
        temp3 = std::make_optional<std::uint64_t>(std::move(m));
    } else {
        std::optional<std::uint64_t> temp4;
        if (y < x) {
            auto temp5 = ([&] {
                auto temp6 = m + 1;
                auto temp7 = std::move(ys);
                temp7.erase(temp7.begin(), std::next(temp7.begin(), temp6));
                auto temp8 = bs(std::move(x), std::move(temp7));

                // Some n \<Rightarrow> Some (m + n + 1)
                if (temp8.has_value()) {
                    auto n = temp8.value();
                    return std::make_optional<std::uint64_t>((m + n) + 1);
                }

                // None \<Rightarrow> None
                return std::optional<std::uint64_t>();
            })();
            temp4 = temp5;
        } else {
            auto temp9 = std::move(m);
            auto temp10 = std::move(ys);
            temp10.erase(std::next(temp10.begin(), temp9), temp10.end());
            temp4 = bs(std::move(x), std::move(temp10));
        }
        temp3 = std::move(temp4);
    }
    return temp3;
}



int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "usage: bs <size>\n"; 
        exit(1);
    }
    
    uint64_t len = strtol(argv[1],NULL,10);
  
    std::deque<std::uint64_t> array;
    
    for (std::uint64_t i=0; i<len; ++i) {
        array.push_back(i*5);
        // std::cout << i*5 << std::endl;
    }
    
    clock_t time = clock();
    
    uint64_t i = 0;
    
    for (std::uint64_t x=0; x<5*len; x+=2){
        // std::cout << "once "<< x << std::endl;
        if( bs(x, array).has_value()){
            i += 1;
            // std::cout << "once "<< i << std::endl;
        }
    }
       
    
    time = clock() - time;  
      
    printf("Time: %fs, (idx checksum: %ld)\n",((double)time)/CLOCKS_PER_SEC,i);
    
    uint64_t time_ms = ((double)time)/CLOCKS_PER_SEC * 1000;
    printf("@ %ld %ld\n",len,time_ms);
    
  }