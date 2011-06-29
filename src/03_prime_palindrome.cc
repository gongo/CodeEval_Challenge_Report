#include <stdlib.h>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    int max = 1000;
    bool isPrime = true;
    std::vector<int> primes;

    for (int i = 2; i < max; i++) {
        isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }

    std::cout << primes.back() << std::endl;

    return EXIT_SUCCESS;
}
