#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_wide(const char *format, int *j, va_list list)
{
	int cury_j;
	int wide = 0;

	for (cury_j = *j + 1; format[cury_j] != '\0'; cury_j++)
	{
		if (is_digit(format[cury_j]))
		{
			wide *= 10;
			wide += format[cury_j] - '0';
		}
		else if (format[cury_j] == '*')
		{
			cury_j++;
			wide = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = cury_j - 1;

	return (wide);
}

