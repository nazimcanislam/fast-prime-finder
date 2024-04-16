#include <stdbool.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

/**
 * This function calculates and returns the elapsed time using Windows libraries.
 * It utilizes the `QueryPerformanceFrequency` and `QueryPerformanceCounter` functions to measure high-resolution time intervals.
 * 
 * @return The elapsed time in seconds.
 */
double get_elapsed_time()
{
    // Declare variables to store the frequency and start time.
    LARGE_INTEGER frequency;   // Stores the frequency of the performance counter.
    LARGE_INTEGER start_time;  // Stores the starting time using the performance counter.

    // Get the frequency of the performance counter.
    QueryPerformanceFrequency(&frequency);

    // Get the current value of the performance counter, representing the start time.
    QueryPerformanceCounter(&start_time);

    // Calculate the elapsed time by dividing the difference in start and end times.
    // by the frequency of the performance counter. This provides time in seconds.
    double elapsed_time = (double)(start_time.QuadPart) / frequency.QuadPart;

    // Return the calculated elapsed time.
    return elapsed_time;
}
#else
#include <time.h>

/**
 * This function calculates and returns the elapsed time using the POSIX `clock_gettime` function
 * with `CLOCK_MONOTONIC` clock type, which provides a monotonically increasing time value.
 * 
 * @return The elapsed time in seconds, measured from an unspecified starting point.
 */
double get_elapsed_time()
{
    // Structure to hold the start time information
    struct timespec start_time;

    // Obtain the current time using the `CLOCK_MONOTONIC` clock type
    // and store it in the start_time structure
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Calculate the elapsed time by adding the seconds and nanoseconds
    // The time is represented as the sum of seconds and nanoseconds divided by 1e9
    // to convert nanoseconds to seconds.
    double elapsed_time = start_time.tv_sec + start_time.tv_nsec / 1e9;
    
    // Return the calculated elapsed time
    return elapsed_time;
}
#endif

/**
 * This function prints colored text to the console using ANSI escape codes.
 * 
 * @param text The text to be printed.
 * @param color The color of the text (possible values: "danger", "success", "primary").
 * @param endline Whether to print a newline character at the end.
 */
void colored_print(char text[], char color[], bool endline)
{
    // ANSI escape codes for colors.
    const char *color_code = "";

    // Determine the color based on the provided color string.
    if (memcmp(color, "danger", 6) == 0)
    {
        printf("\033[0;31");  // Red color
    }
    else if (memcmp(color, "success", 6) == 0)
    {
        printf("\033[0;32m");  // Green color
    }
    else if (memcmp(color, "primary", 7) == 0)
    {
        printf("\033[0;34m");  // Blue color
    }

    // Print the text with the selected color.
    printf("%s%s\033[0m", color_code, text);

    // Print a newline character
    if (endline)
    {
        printf("\n");
    }
}
