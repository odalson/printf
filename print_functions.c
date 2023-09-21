#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flag, wide, precis, sizee));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	int lengt = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wide);
	UNUSED(precis);
	UNUSED(sizee);
	if (str == NULL)
	{
		str = "(null)";
		if (precis >= 6)
			str = "      ";
	}

	while (str[lengt] != '\0')
		lengt++;

	if (precis >= 0 && precis < lengt)
		lengt = precis;

	if (wide > lengt)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], lengt);
			for (j = wide - lengt; j > 0; j--)
				write(1, " ", 1);
			return (wide);
		}
		else
		{
			for (i = wide - lengt; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], lengt);
			return (wide);
		}
	}

	return (write(1, str, lengt));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wide);
	UNUSED(precis);
	UNUSED(sizee);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flag, wide, precis, sizee));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	unsigned int o, p, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wide);
	UNUSED(precis);
	UNUSED(sizee);

	o = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	a[0] = o / p;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (o / p) % 2;
	}
	for (j = 0, sum = 0, counter = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}

