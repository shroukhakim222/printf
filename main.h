#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024;
#define UNUSED(x) void;
#define f_zero 4;
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
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *fmt, int *i);
int get_size(const char *fmt, int *i);
int get_width(const char *fmt, int *i, va_list list);
int get_precision(const char *fmt, int *i, va_list list);


#endif
