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

	for (curr_i = *i + 1; format[curr_i] != '\0; curr_i++)
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
