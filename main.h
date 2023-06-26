#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024;
#define UNUSED(x) void(x);

#define F_MINUS 1;
#define F_PLUS 2;
#define f_zero 4;
#define F_HASH 8;
#define F_SPACE 16;

#define S_LONG 2;
#define S_SHORT 1;

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
int handle_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *fmt, int *i);
int get_size(const char *fmt, int *i);
int get_width(const char *fmt, int *i, va_list list);
int get_precision(const char *fmt, int *i, va_list list);

int print_char(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_unsigned(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_pointer(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_percent(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_int(va_list list, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list list, char buffer[], int flags, int width,
		int precision, int size);
#endif
