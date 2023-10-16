#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
int _putchar(int c);
int _printf(const char *format, ...);
int printer(char formartSpecifier, va_list arg);
unsigned int _putdig(unsigned int num, unsigned int base);
int _putstr(char *str);
int _putint(int n);

#endif
