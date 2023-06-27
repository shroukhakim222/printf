#include "main.h"
#include <unistd.h>

void buff_print(char buffer[], int *ind);

/**
 * _printf - function print anything to stdout
 * @format: format
 * Return: printed string
 */

int _printf(const char *format, ...)
{
	int i, ind, printed;
	char buffer[BUFFER_SIZE];
	va_list list;
	int flags, width, size, precision;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[ind++] = format[i];
			if (ind == BUFFER_SIZE)
				buff_print(buffer, &ind);
		}
		else
		{
			buff_print(buffer, &ind);
			flags = get_flags(format, &i);
			precision = get_precision(format, &i, list);
			width = get_width(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
		}
	}
	buff_print(buffer, &ind);
	va_end(list);
	return (0);
}

/**
 * buff_print - print buffer
 * @buffer: buffer to be printed
 * @ind: buffer index
 * Return: void
 */

void buff_print(char buffer[], int *ind)
{
	if (*ind > 0)
		write(1, &buffer[0], *ind);
	*ind = 0;
}
