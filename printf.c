#include "main.h"

/**
 * _printf - works like printf
 * @format: the pointer to the line of argiments
 * Return: number of bytes used.
 * Description: the function checks for an argument
 *				then cheks if the character following the argument
 *				is a % sign. If it is, then it callt on the.
 *				printer function the selects another function
 *				depending on the format specifier.
*/
int _printf(const char *format, ...)
{
	int count;
	va_list arg;

	count = 0;
	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += printer(*++format, arg);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(arg);
	return (count);
}
