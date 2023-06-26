#include "main.h"

/**
 * print_percent - print percent
 * @list: list
 * @buffer: pointer to buffer
 * @flags: number of flags
 * @width: the width
 * @size: the size
 * @precision: precision
 * Return: printes symbol
 */

int print_percent(va_list list, char buffer[], int flags,
		int width, int precision, int size);
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, %%, 1));
}
