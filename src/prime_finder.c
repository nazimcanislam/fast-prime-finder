#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>

double get_elapsed_time()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER start_time;
    LARGE_INTEGER end_time;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);

    // Yapılacak işlemler

    QueryPerformanceCounter(&end_time);

    double elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
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
    if (number < 2) {
        return false;
    }

    if (number == 2 || number == 3) {
        return true;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    // Checking divisibility for numbers of the form 6k ± 1 up to sqrt(number).
    int sqrt_num = sqrt(number);
    for (int i = 5; i <= sqrt_num; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

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
