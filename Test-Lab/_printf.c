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
int _putint(unsigned int n);

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	/* printf("Negative:[%d]\n", -762534);*/
	_printf("Unsigned:[%u]\n", ui);
	/* printf("Unsigned:[%u]\n", ui);*/
	_printf("Unsigned octal:[%o]\n", ui);
	/* printf("Unsigned octal:[%o]\n", ui);*/
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	/* printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);*/
	_printf("Character:[%c]\n", 'H');
	/* printf("Character:[%c]\n", 'H');*/
	_printf("String:[%s]\n", "I am a string !");
	/* printf("String:[%s]\n", "I am a string !");*/
	_printf("Address:[%p]\n", addr);
	/* printf("Address:[%p]\n", addr);*/
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	/* printf("Unknown:[%r]\n");*/
	return (0);
}

/**
 * _printf - works like printf
 * @format: the pointer to the line of argiments
 * 
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
	{
		count = _putchar(va_arg(arg, int));
	}
	else if (formatSpecifier == 's')
	{
		count = _putstr(va_arg(arg, char *));
	}
	else if (formatSpecifier == 'i' || formatSpecifier == 'd')
	{
		if (va_arg(arg, int) < 0)
		{
			count = _putchar('-');
			count += _putint(va_arg(arg, int));
		}
		else
		{
			count = _putint(va_arg(arg, int));
		}
	}
	else if (formatSpecifier == 'x' || formatSpecifier == 'X')
	{
		if (formatSpecifier == 'x')
		{
			base = 10;
		}
		else if (formatSpecifier == 'X')
		{
			base = 16;
		}
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
	int final;

	final = 0;
	while (*str)
	{
		final += write(1, str++, 1);
	}
	return (final);
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
	char *symbolsx;
	char *symbolsX;
	unsigned int counter;

	/*Base 10 Hex*/
	symbolsx = "123456789abcdef";
	/*Base 16 Hex*/
	symbolsX = "123456789ABCDEF";

	if (num < base)
	{
		if(base < 10)
		{
			return (_putchar(symbolsx[num]));
		}
		else
		{
		return (_putchar(symbolsX[num]));
		}
	}
	else
	{
		counter = _putdig(num / base, base);
		return (counter + _putdig(num % base, base));
	}
}

/**
 * _putint - formats an intager
 * @n: unsigned int
 * Return: value of final int
 * 
 * Description: This a recursive function
 *				breaks down argument parsed to write out an Intager
 *				if the argument > 10
*/
int _putint(unsigned int n)
{
	int counter;
	if (n > 10)
	{
		counter = _putint(n / 10);
		return (counter + _putint(n % 10));
	}
	else
	{
		return (write(1, &n, 1));
	}
}
