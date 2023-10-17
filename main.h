#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/*format picking function*/
int printer(char formartSpecifier, va_list arg);

/*formating functions*/
int _putchar(va_list arg);
int _printf(const char *format, ...);
int _putdig(va_list arg);
int _putstr(va_list arg);
int _putint(va_list arg);
int _putui(va_list arg);

/*auxilary functions*/
int realdig(int num);
int realchar(int c);

typedef struct FunctionFormats
{
	int (*function)(va_list);
	char specifierLEtter;
} FunctionFormats;

#endif
