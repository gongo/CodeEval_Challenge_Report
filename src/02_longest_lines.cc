/**
 * Longest Lines
 *
 * @link     http://www.codeeval.com/open_challenges/2/
 * @license  MAHALO License (https://github.com/gongo/Tython/blob/master/LICENSE)
 * @example
 *
 *   1. input file
 *
 *      2
 *      Hello World
 *      
 *      CodeEval
 *      Quick Fox
 *      A
 *      San Francisco
 * 
 *   2. run
 *
 *      gongo% ./a.out input.txt
 *      San Francisco
 *      Hello World
 *      gongo%
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string>

bool compareString(const std::string& left, const std::string& right) {
    return left.length() > right.length();
}

int getNumber(std::ifstream& ifs)
{
    std::string line;

    getline(ifs, line);
    return atoi(line.c_str());
}

std::vector<std::string> getLines(std::ifstream& ifs)
{
    std::string line;
    std::vector<std::string> lines;

    while (getline(ifs, line)) {
        lines.push_back(line);
    }

    return lines;
}

int main(int argc, char** argv)
{
    int number;
    std::vector<std::string> lines;
    std::ifstream ifs;

    ifs.open(argv[1]);
    number = getNumber(ifs);
    lines = getLines(ifs);
    ifs.close();

    std::sort(lines.begin(), lines.end(), compareString);

    for (int i = 0; i < number; i++) {
        std::cout << lines[i] << std::endl;
    }
    
    return EXIT_SUCCESS;
}
