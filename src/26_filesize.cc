#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char** argv)
{
    std::ifstream ifs;

    ifs.open(argv[1]);
    std::cout << ifs.rdbuf()->in_avail() << std::endl;
    ifs.close();
    
    return EXIT_SUCCESS;
}
