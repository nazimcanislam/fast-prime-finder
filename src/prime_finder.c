#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

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
	int size = 11;
	int total = 0;
	char s_number[size];
	sprintf(s_number, "%d", number);

	for (int i = 0; i < size; ++i)
	{
		total += s_number[i];
	}

	if (total % 3 == 0)
	{
		return false;
	}
	// -------------------------------

	// -------------------------------
	// Finding square root of number and divide every blew number.
	double root = sqrt((double)number);
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

	printf(text);
	printf("\033[0m");

	if (endline)
	{
		printf("\n");
	}
}

int save_primes_to_file(char path[], int primes[], int size)
{
	FILE *file;
	file = fopen(path, "w");

	if (file == NULL)
	{
		return 1;
	}

	for (int i = 0; i < size; ++i)
	{
		char str[10];

		if (i + 1 != size)
		{
			sprintf(str, "%d,", primes[i]);
		}
		else
		{
			sprintf(str, "%d", primes[i]);
		}

		fprintf(file, "%s", str);
	}
	fclose(file);

	return 0;
}

long int get_file_size(char path[])
{
	FILE *file = fopen(path, "r");

	fseek(file, 0L, SEEK_END);
	long int size = ftell(file);
	fclose(file);

	return size;
}
