#include "main.h"

void print_buff(char buff[], int *buffer_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, print = 0, print_chars = 0;
	int flag, wide, precis, sizee, buffer_ind = 0;
	va_list list;
	char buff[BUFF_SIZEE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[buffer_ind++] = format[j];
			if (buffer_ind == BUFF_SIZEE)
				print_buff(buff, &buffer_ind);
			/* write(1, &format[j], 1);*/
			print_chars++;
		}
		else
		{
			print_buff(buff, &buffer_ind);
			flag = get_flag(format, &j);
			wide = get_wide(format, &j, list);
			precis = get_precis(format, &j, list);
			sizee = get_sizee(format, &j);
			++j;
			print = handle_print(format, &j, list, buff,
				flag, wide, precis, sizee);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buff(buff, &buffer_ind);

	va_end(list);

	return (print_chars);
}

/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buff: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buff(char buff[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buff[0], *buffer_ind);

	*buffer_ind = 0;
}

