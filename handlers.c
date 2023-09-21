#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flag, int wide, int precis, int sizee)
{ /* char is stored at left and paddind at buffer's right */
	int j = 0;
	char pad = ' ';

	UNUSED(precis);
	UNUSED(sizee);

	if (flag & F_ZERO)
		pad = '0';

	buffer[j++] = c;
	buffer[j] = '\0';

	if (wide > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < wide - 1; j++)
			buffer[BUFF_SIZE - i - 2] = pad;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], wide - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], wide - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int index, char buffer[],
	int flag, int wide, int precis, int sizee)
{
	int leng = BUFF_SIZE - index - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(sizee);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (write_num(index, buffer, flag, wide, precis,
		leng, pad, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int index, char buffer[],
	int flag, int wide, int preg,
	int leng, char pad, char extra_c)
{
	int j, pad_start = 1;

	if (preg == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && wide == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (preg == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (preg > 0 && preg < leng)
		pad = ' ';
	while (preg > leng)
		buffer[--index] = '0', leng++;
	if (extra_c != 0)
		leng++;
	if (wide > leng)
	{
		for (j = 1; j < wide - leng + 1; j++)
			buffer[j] = pad;
		buffer[j] = '\0';
		if (flag & F_MINUS && pad == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], leng) + write(1, &buffer[1], j - 1));
		}
		else if (!(flag & F_MINUS) && pad == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], leng));
		}
		else if (!(flag & F_MINUS) && pad == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], j - pad_start) +
				write(1, &buffer[index], leng - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], leng));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int index,
	char buffer[],
	int flag, int wide, int precis, int sizee)
{
	/* The number is stored at the bufer's right and starts at position i */
	int leng = BUFF_SIZE - index - 1, j = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(sizee);

	if (precis == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precis > 0 && precis < leng)
		pad = ' ';

	while (precis > leng)
	{
		buffer[--index] = '0';
		leng++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';

	if (wide > leng)
	{
		for (j = 0; j < wide - leng; j++)
			buffer[j] = pad;

		buffer[j] = '\0';

		if (flag j & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[index], leng) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], leng));
		}
	}

	return (write(1, &buffer[index], leng));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int index, int leng,
	int wide, int flag, char pad, char extra_c, int pad_start)
{
	int j;

	if (wide > leng)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = pad;
		buffer[j] = '\0';
		if (flag & F_MINUS && pad == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && pad == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], leng));
		}
		else if (!(flag & F_MINUS) && pad == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[index], leng - (1 - pad_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

