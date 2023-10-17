#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

/**
 * int_to_binary - print unassigned number
 * @num: unassigned interger to be converted to binary
 * @custom_printf: conversion specifier
 * @main: the main function
 *
 * Return: numbers of character printed
 *
 */

void int_to_binary(uint32_t num)
{
    if (num == 0) 
    {
        putchar('0');
        return;
    }

    int binary[32];
    int index = 0;

    while (num > 0) 
    {
        binary[index++] = num % 2;
        num /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        putchar('0' + binary[i]);
    }
}
int custom_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format)
    {
        if (*format != '%')
	{
            char_count += write(1, format, 1)
        } else
	{
            format++;
            switch (*format)
	    {
                case 'd':
                case 'i': 
		{
                    int num = va_arg(args, int);
                    char_count += printf("%d", num);
                    break;
                }
                case 'b':
		{
                    uint32_t num = va_arg(args, uint32_t);
                    int_to_binary(num);
                    char_count += 32;
                    break;
                }
                default:
		char_count += write(1, "%", 1);
		    char_count += write(1, format, 1);
            }
        }
        format++;
    }
    va_end(args);
    return char_count;
}
int main()
{
    int num = 42;
    uint32_t bin = 18;
    custom_printf("This is a number in binary: %b\n", bin);
    custom_printf("Another number: %i\n", num);
    return 0;
}
