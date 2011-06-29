/**
 * Odd Numbers
 *
 * @link     http://www.codeeval.com/open_challenges/25/
 * @license  MAHALO License (https://github.com/gongo/Tython/blob/master/LICENSE)
 */

#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
    for (int i = 1; i <= 99; i++) {
        if (i % 2 == 1) {
            std::cout << i << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}
