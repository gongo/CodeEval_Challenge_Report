/**
 * Endianness
 *
 * @link     http://www.codeeval.com/open_challenges/15/
 * @license  MAHALO License (https://github.com/gongo/Tython/blob/master/LICENSE)
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a = 1;

    if (*(char *)&a) {
        printf("LittleEndian\n");
    } else {
        printf("BigEndian\n");
    }

    return EXIT_SUCCESS;
}
