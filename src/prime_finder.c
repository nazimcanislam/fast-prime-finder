#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>

double get_elapsed_time()
{
    LARGE_INTEGER start_time, end_time, frequency;
    double elapsed_time;

    // Get the frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Get the starting time
    QueryPerformanceCounter(&start_time);

    // Perform some operation or code to measure its execution time

    // Get the ending time
    QueryPerformanceCounter(&end_time);

    // Calculate the elapsed time in seconds
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;

    return elapsed_time;
}
#else
#include <time.h>

double get_elapsed_time()
{
	struct timespec start_time;
	clock_gettime(CLOCK_MONOTONIC, &start_time);

	return start_time.tv_sec + start_time.tv_nsec / 1e9;
}
#endif

bool is_prime(int number)
{
	// Prime numbers less than 8 are: 2, 3, 5, 7.
	// So return true if the number is equal to one of these, otherwise return false.
	// If the number is greater than 8, it is not prime if it is divisible by 2 or 5.
	if (number < 8)
	{
		if (number == 2 || number == 3 || number == 5 || number == 7)
		{
			return true;
		}

		return false;
	}
	else
	{
		if (number % 2 == 0)
		{
			return false;
		}

		if (number % 5 == 0)
		{
			return false;
		}
	}

	// -------------------------------
	// If the sum of the numbers is divisible by 3, the number is not prime.
	int total = 0;
	int temp = number;
	while (temp > 0)
	{
		total += temp % 10;
		temp /= 10;
	}

	if (total % 3 == 0)
	{
		return false;
	}
	// -------------------------------

	// -------------------------------
	// Finding square root of number and divide every blew number.
	double root = sqrt(number);
	for (int i = 2; i <= root; ++i)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	// -------------------------------

	// If the number passes all phases, it is prime.
	return true;
}

void colored_print(char text[], char color[], bool endline)
{
	if (memcmp(color, "danger", 6) == 0)
	{
		printf("\033[0;31");
	}
	else if (memcmp(color, "success", 6) == 0)
	{
		printf("\033[0;32m");
	}
	else if (memcmp(color, "primary", 7) == 0)
	{
		printf("\033[0;34m");
	}

	printf("%s", text);
	printf("\033[0m");

	if (endline)
	{
		printf("\n");
	}
}
