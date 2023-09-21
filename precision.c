#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
	int cur_j = *j + 1;
	int prec = -1;

	if (format[cur_j] != '.')
		return (prec);

	prec = 0;

	for (cur_j += 1; format[cur_j] != '\0'; cur_j++)
	{
		if (is_digit(format[cur_j]))
		{
			prec *= 10;
			prec += format[cur_j] - '0';
		}
		else if (format[cur_j] == '*')
		{
			cur_j++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = cur_j - 1;

	return (precision);
}

