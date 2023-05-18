#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>

#include "prime_finder.h"

#define NUM_THREADS 4

typedef struct {
	int range_start;
	int range_end;
	unsigned int *count;
	FILE *file;
	bool *save;
} ThreadArgs;

void *find_primes(void *arg)
{
	ThreadArgs *args = (ThreadArgs*) arg;
	int range_start = args->range_start;
	int range_end = args->range_end;
	unsigned int *count = args->count;
	FILE *file = args->file;

	int prime_count = 0;
	for (int i = range_start; i <= range_end; ++i)
	{
		if (is_prime(i))
		{
			if (*args->save)
			{
				fprintf(file, "%d\n", i);
			}
			prime_count++;
		}
	}

	*count += prime_count;

	pthread_exit(NULL);
}

/**
 * @brief Main entry point function of program.
 */
int main(int argc, char const *argv[])
{
	// Define start and end number and get them from user.
	int range_start, range_end;
	printf("Enter start number: ");
	scanf("%d", &range_start);
	getchar();
	printf("Enter end number: ");
	scanf("%d", &range_end);
	getchar();

	bool save = false;
	bool *save_pointer = &save;
	char choice;
	printf("Do you want to save primes to file?\n\033[1;33mWARNING:\033[0m The file might be huge sized!\nAre you sure [Y/N]: ");
	scanf("%c", &choice);
	FILE *file = NULL;
	const char *file_name = "primes.txt";
	if (choice == 'Y' || choice == 'y')
	{
		save = true;
		file = fopen(file_name, "w");

		if (file == NULL)
		{
			printf("\033[1;31mFile couldn't open!\033[0m");
			return 1;
		}
	}
	else
	{
		free(file);
	}

	int step = (range_end - range_start + 1) / NUM_THREADS;

	pthread_t threads[NUM_THREADS];
	ThreadArgs thread_args[NUM_THREADS];
	unsigned int total_count = 0;

	double start_time = get_elapsed_time();

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		thread_args[i].range_start = range_start + i * step;
		thread_args[i].range_end = range_start + (i + 1) * step - 1;
		thread_args[i].count = &total_count;
		thread_args[i].file = file;
		thread_args[i].save = save_pointer;

		pthread_create(&threads[i], NULL, find_primes, (void*)&thread_args[i]);
	}

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		pthread_join(threads[i], NULL);
	}

	if (save)
	{
		fclose(file);
		printf("\nPrimes saved \033[1;32msuccessfuly\033[0m!\n");
	}

	double end_time = get_elapsed_time();

	// Calculate the elapsed time and print it on the screen.
	double diff_time = end_time - start_time;
	printf("\nFound \033[0;34m%d\033[0m primes between \033[0;34m%d\033[0m and \033[0;34m%d\033[0m in \033[0;34m%f\033[0m seconds.\n", total_count, range_start, range_end, diff_time);

	if (save)
	{
		struct stat st;
		if (stat(file_name, &st) == 0)
		{
			long long file_size = st.st_size;
			printf("File size: %lld ", file_size);

			if (file_size > 1)
			{
				printf("bytes\n");
			}
			else if (file_size == 1)
			{
				printf("byte\n");
			}
		}
		else
		{
			printf("\033[0;31mERROR:\033[0m Couldn't get file size.\n");
		}
	}

	// Return success status.
	return 0;
}
