#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string>

int sum_of_squares(int num)
{
    int sum = 0;
    int target = 0;
    
    while (num != 0) {
        target = (num % 10);
        sum += target*target;
        num /= 10;
    }

    return sum;
}

bool isHappy(int num)
{
    while (1) {
        num = sum_of_squares(num);
        if (num == 1) {
            return true;
        } else if (num == 4) {
            return false;
        }
    }
}

int main(int argc, char** argv)
{
    std::ifstream ifs;
    std::string line;

    ifs.open(argv[1]);
    while (getline(ifs, line)) {
        if (isHappy(atoi(line.c_str()))) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    ifs.close();

    return EXIT_SUCCESS;
}
