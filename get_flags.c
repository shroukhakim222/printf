#include "main.h"


/**
 * get_flags - caluclate flags
 * @format: pointer to array
 * @i: take a parameter
 *
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	const char sign[] = {'-', '+', '0', '#', ' ', '\0'};
	const char arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int j, curr_i;
	int flags = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; sign[j] != '\0';j++)
		{
			if (format[curr_i] == sign[j])
			{
				flags |= arr[j];
				break;
			}
			if (sign[j] == 0)
				break;
		}
	}
	*i = curr_i - 1;
	return (flags);
}

#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
