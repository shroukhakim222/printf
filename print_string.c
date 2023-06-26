#include "main.h"

/**
 * print_string - function that print string
 * @list: list
 * @buffer: buffer
 * @width: width
 * @precision: precision
 * @size: size
 * @flags: flags
 * Return: printed string
 */

int print_string(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	int len;
	char *str = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		length = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return(width);
		}
		return(write(1, str, len));
	}
}
