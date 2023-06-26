#include "main.h"

/**
 * print_char - function that print char
 * @list: pointer to list
 * @buffer: array of value
 * @flags: calculate the active flags
 * @width: git width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: printed char
 */

int print_char(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(list, int);
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, buffer[BUFF_SIZE - i - 1],
						width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
					+ write(1, &buffer[0], 1));
	}
	return (write(1, buffer[0], 1));
}
