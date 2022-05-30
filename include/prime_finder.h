#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/**
 * @brief Quickly finds whether it is prime, even if the number sent as a parameter is very large.
 * 
 * @param number Number to check
 * @return true If it is prime
 * @return false If it is not prime
 */
bool is_prime(int number);

/**
 * @brief Prints text in color.
 * 
 * @param text Text to print
 * @param color Color name: "primary", "danger", "success"
 * @param endline Go to the bottom line after printed?
 */
void colored_print(char text[], char color[], bool endline);

/**
 * @brief Saves prime numbers to file.
 * 
 * @param path Where to save
 * @param primes Primes array data
 * @param size Count of primes
 * @return int Status code
 */
int save_primes_to_file(char path[], int primes[], int size);

/**
 * @brief Gets the file size.
 * 
 * @param path File path
 * @return char File size 
 */
long int get_file_size(char path[]);
