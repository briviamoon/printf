#include "main.h"

/**
 * printer - this is format selector function.
 * @formatSpecifier: this is the s, c, d ...
 * @arg: This is the list of arguments passed.
 * Return: the value fom the called function.
 * Description: The function choosed a function
 *				that formats output depending on the specifier
 *				I chooses using "ar_arg" whether to pas a type
 *				to a specific funcion as per the specifier.
 *				Not theat During arg passing to the {...}
 *				types are promoted eg char becomes an Int.
 */
int printer(char formatSpecifier, va_list arg)
{
	int count;
	unsigned int base;

	count = 0;
	if (formatSpecifier == 'c')
		count += _putchar(va_arg(arg, int));
	else if (formatSpecifier == 's')
		count += _putstr(va_arg(arg, char *));
	else if (formatSpecifier == '%')
		count += _putchar('%');
	else if (formatSpecifier == 'i' || formatSpecifier == 'd')
		if (va_arg(arg, int) < 0)
		{
			count += _putchar('-');
			count += _putint(va_arg(arg, int));
		}
		else
		{
			count += _putint(va_arg(arg, int));
		}
	else if (formatSpecifier == 'x' || formatSpecifier == 'X')
	{
		if (formatSpecifier == 'x')
			base = 10;
		else if (formatSpecifier == 'X')
			base = 16;
		count = _putdig((va_arg(arg, unsigned int)), base);
	}
	else
	{
		count += write(1, &formatSpecifier, 1);
	}
	return (count);
}

/**
 * _putchar - formats a char
 * @c: character promoted to an int
 * Return: number of bytes writen to stdout
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - formats a string
 * @str: pointer to string
 * Return: bytes used in stdout
 */
int _putstr(char *str)
{
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

/**
 * _putdig - formats Hexes on base 10 and 16
 * @num: uns int representation oh Hex
 * @base: base of the hex {10 || 16}
 * Return: value from function calls
 *
 * Description: The function I recursive
 *				in case 1 it evaluates if base > num
 *				If this is true, it calls on putchar
 *				to write the values equivical to the sybols
 *				Onto the stdout.
 *				The 2nd case cals itself to systematicaly
 *				ubundele the number util cale 1 is reached
 */

unsigned int _putdig(unsigned int num, unsigned int base)
{
	char *symbols;
	int counter = 0;

	symbols = "123456789ABCDEF";

	if (num < base)
	{
		counter += _putchar(symbols[num]);
		return (counter);
	}
	else
	{
		counter += _putdig(num / base, base);
		counter += _putdig(num % base, base);
		return (counter);
	}
}

/**
 * _putint - formats an intager
 * @n: unsigned int
 * Return: value of final int bytes
 *
 * Description: This a recursive function
 *				breaks down argument parsed to write out an Intager
 *				if the argument > 10
 */
int _putint(int n)
{
	int counter = 0;

	if (n >= 10)
	{
		counter += _putint(n / 10);
		counter += _putint(n % 10);
		return (counter);
	}
	else
	{
		return (_putchar('0' + n));
	}
}
