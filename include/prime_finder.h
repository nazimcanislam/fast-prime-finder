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

double get_elapsed_time();
