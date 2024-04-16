#pragma once

#include <stdbool.h>
#include <stdio.h>

/**
 * Prints colored text to the console using ANSI escape codes.
 * 
 * @param text The text to be printed.
 * @param color The color of the text (possible values: "danger", "success", "primary").
 * @param endline Whether to print a newline character at the end.
 */
void colored_print(char text[], char color[], bool endline);

/**
 * Calculates and returns the elapsed time using platform-specific libraries.
 * 
 * @return The elapsed time in seconds.
 */
double get_elapsed_time();
