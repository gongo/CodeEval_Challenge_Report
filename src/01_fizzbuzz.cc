/**
 * Fizz Buzz
 *
 * @link     http://www.codeeval.com/open_challenges/1/
 * @license  MAHALO License (https://github.com/gongo/Tython/blob/master/LICENSE)
 * @example
 *
 *   1. input file
 *
 *      gongo% cat input.txt
 *      3 5 10
 *      2 7 15
 *      gongo%
 *
 *   2. run
 *
 *      gongo% ./a.out input.txt
 *      1 2 F 4 B F 7 8 F B
 *      1 F 3 F 5 F B F 9 F 11 F 13 FB 15
 *      gongo%
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

void parse(char* line, int* a, int* b, int* n)
{
    char* pos;
    const char* delims = " ";

    pos = strtok(line, delims);
    *a = atoi(pos); pos = strtok(NULL, delims);
    *b = atoi(pos); pos = strtok(NULL, delims);
    *n = atoi(pos);
}

void fizzbuzz(int a, int b, int n)
{
    for (int i = 1; i <= n; i++) {
        if (i % (a*b) == 0) {
            std::cout << "FB ";
        } else if (i % a == 0) {
            std::cout << "F ";
        } else if (i % b == 0) {
            std::cout << "B ";
        } else {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::ifstream ifs(argv[1]);
    std::string line;

    while (getline(ifs, line)) {
        int a, b, n;
        parse(strdup(line.c_str()), &a, &b, &n);
        fizzbuzz(a, b, n);
    }
    
    return EXIT_SUCCESS;
}
