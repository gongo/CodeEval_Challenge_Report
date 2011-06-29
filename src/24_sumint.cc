#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
    std::ifstream ifs;
    std::string line;
    int sum = 0;

    ifs.open(argv[1]);
    while (getline(ifs, line)) {
        sum += atoi(line.c_str());
    }
    std::cout << sum << std::endl;
    ifs.close();

    return EXIT_SUCCESS;
}
