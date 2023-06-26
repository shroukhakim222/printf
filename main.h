#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct tmp_fun - struct to choose type
 * @fmt: format
 * @fn: pointer to function
 */

struct tmp_fun
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int)
};
/**
 * fun - typedef struct
 */
typedef tmp_fun fun;

int _printf(const char *format, ...);

#endif
