#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// Making program more cross-platform.
#ifdef _WIN32
#include <window.h>
#else
#include <unistd.h>
#endif

#include "prime_finder.h"

/**
 * @brief Main entry point function of program.
 */
int main(int argc, char const *argv[])
{
	// Define time_t variables to store elapsed time.
	time_t start_time;
	time_t end_time;

	// Define start and end number and get them from user.
	int start_number;
	int end_number;
	printf("Enter start number: ");
	scanf("%d", &start_number);
	printf("Enter end number: ");
	scanf("%d", &end_number);

	// Define an array and index number to store prime numbers.
	int *primes = malloc(sizeof(*primes) * end_number);	
	int index = 0;

	// Start the timer.
	time(&start_time);

	// Find and insert primes into primes[] array.
	for (int i = start_number; i <= end_number; ++i)
	{    
		if (is_prime(i))
		{
			primes[index] = i;
			++index;
		}
	}

	// End the timer.
	time(&end_time);

	// Calculate the elapsed time and print it on the screen.
	double diff_time = round(difftime(end_time, start_time));
	printf("\nFound \033[0;34m%d\033[0m primes between \033[0;34m%d\033[0m and \033[0;34m%d\033[0m in \033[0;34m%f\033[0m seconds.\n", index, start_number, end_number, diff_time);

	// Save prime numbers to file.
	char path[23] = "prime_finder_result.txt";
	printf("\nPrime numbers saved to file: ");
	if (save_primes_to_file(path, primes, index) == 0)
	{
		colored_print("SUCCESS", "success", true);
		printf("Path: %s\n", realpath(path, NULL));
	}
	else
	{
		colored_print("FAIL", "danger", true);
	}
	long int file_size = get_file_size(path);
	printf("File size: %ld bytes\n", file_size);

	// Return success status.
	return 0;
}
