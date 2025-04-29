#include <iostream>
#include <fstream>
#include <cstdlib>  // 包含rand()和srand()
#include <ctime>    // 包含time()

int main() {
    int num;
    std::cout << "please enter the size of random numbers that you want to generate: ";
    std::cin >> num;

    if (num <= 0) {
        std::cerr << "error! It must > 0!" << std::endl;
        return 1;
    }

    // 使用当前时间作为随机数生成器的种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 打开文件以写入模式
    std::ofstream outFile("random_numbers.txt");
    if (!outFile) {
        std::cerr << "open file and write error!" << std::endl;
        return 1;
    }

    int max = num*10;
    int min = max * (-1);

    // 生成随机整数并写入文件
    for (int i = 0; i < num; ++i) {
        // int randomNumber = std::rand();  // 生成一个随机整数
        int randomNumber = min + (std::rand() % (max - min + 1));
        outFile << randomNumber << std::endl;
    }

    // 关闭文件
    outFile.close();
    std::cout << "Data already in random_numbers.txt!" << std::endl;

    return 0;
}