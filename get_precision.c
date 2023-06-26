#include "main.h"

/**
 * is_digit - check if the character
 * is digit
 * @c: character to be checked
 * Return: 1 if true & 0 if false
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * get_precision - calculate precision
 * @format: format pointer aarray
 * @i: list of argument
 * @list: list
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;
	for (curr_i += 1; format[curr_i] != '/0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	i = curr_i - 1;
	return (precision);
}
