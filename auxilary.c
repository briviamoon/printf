#include "main.h"

/**
 * realdig - formats i and d
 * @num: intager arg
 * Return: number of bytes used.
 * Description: this function is called from _putdig
 * It takes in an int instead of a va_list pointer.
 * So in a way it is a helper for the _putdig function
 */

int realdig(int num)
{
	char *symbols = NULL;
	int counter = 0;
	int base;
	unsigned long i;

	FunctionFormats Formatfunctions[] = {
		{_putdig, 'x'},
		{_putdig, 'X'},
	};

	for (i = 0; i < sizeof(Formatfunctions) / sizeof(Formatfunctions[0]); i++)
	{
		if (Formatfunctions[i].specifierLEtter == 'x')
		{
			base = 16;
			symbols = "123456789abcdef";
		}
		else if (Formatfunctions[i].specifierLEtter == 'X')
		{
			base = 16;
			symbols = "123456789ABCDEF";
		}
		else
		{
			base = 10;
			symbols = "0123456789";
		}
	}

	if (num < base)
	{
		counter += realchar(symbols[num]);
		return (counter);
	}
	else
	{
		counter += realdig(num / base);
		counter += realdig(num % base);
		return (counter);
	}
}

/**
 * realchar - writer chars to std out
 * @c: char graduates to int and given as param
 * Return: number of bytes used
 */
int realchar(int c)
{
	return (write(1, &c, 1));
}
