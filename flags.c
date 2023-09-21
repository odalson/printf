#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flag(const char *format, int *j)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_j;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j= *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_j] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

		*i = curr_j - 1;

	return (flag);
}

