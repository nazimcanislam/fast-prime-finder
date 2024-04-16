#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/**
 * Checks whether a given interger is a prime number.
 * 
 * @param number The interger to be checked for primality.
 * @return true if number is prime, false otherwise.
 */
bool is_prime(int number)
{
    // Special cases: 0, 1, and negative numbers are not prime
    if (number < 2)
    {
        return false;
    }

    // Base cases: 2 and 3 are prime
    if (number == 2 || number == 3)
    {
        return true;
    }

    // Check divisibility by 2 and 3
    if (number % 2 == 0 || number % 3 == 0)
    {
        return false;
    }

    // Check divisibility for numbers of the form 6k ± 1 up to sqrt(number)
    int sqrt_num = sqrt(number);
    for (int i = 5; i <= sqrt_num; i += 6)
    {
        // Check divisibility by numbers of the form 6k ± 1 and 6k ± 1 + 2
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return false;
        }
    }

    // If no divisors are found, the number is prime
    return true;
}
