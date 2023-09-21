#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_sizee(const char *format, int *j)
{
	int cur_j = *j + 1;
	int sizee = 0;

	if (format[cur_j] == 'l')
		sizee = S_LONG;
	else if (format[cur_j] == 'h')
		sizee = S_SHORT;

	if (sizee == 0)
		*j = cur_j - 1;
	else
		*j = cur_j;

	return (sizee);
}

