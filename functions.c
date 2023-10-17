#include "main.h"

/**
 * _putchar - formats a char
 * @arg: list of va_arg list.
 * Return: number of bytes writen to stdout
 */
int _putchar(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	return (write(1, &c, 1));
}

/**
 * _putstr - formats a string
 * @arg: list of var_arg list.
 * Return: bytes used in stdout
 */
int _putstr(va_list arg)
{
	int count = 0;
	char *str = va_arg(arg, char *);

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

/**
 * _putdig - formats Hexes on base 10 and 16
 * @arg: list of arg_list.
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

int _putdig(va_list arg)
{
	char *symbols = NULL;
	int counter = 0;
	int num, base;
	long unsigned int i;


	FunctionFormats Formatfunctions[] = {
		{_putdig, 'x'},
		{_putdig, 'X'},
		{_putui, 'u'},
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

	num = va_arg(arg, unsigned int);

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
 * _putint - formats an intager
 * @arg: list of va_arg list.
 * Return: value of final int bytes
 *
 * Description: This a recursive function
 *				breaks down argument parsed to write out an Intager
 *				if the argument > 10
 */

int _putint(va_list arg)
{
	int num;
	int count = 0;
	int temp, digits, digit, divisor;
	int i, j;

	num = va_arg(arg, int);
	if (num < 0)
	{
		realchar('-');
		count++;
		num = -num;
	}
	temp = num;
	digits = 0;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	temp = num;
	for (i = 0; i < digits; i++)
	{
		divisor = 1;
		for (j = i + 1; j < digits; j++)
		{
			divisor *= 10;
		}
		digit = (temp / divisor) % 10;
		realchar('0' + digit);
		count++;
	}
	return (count);
}

/**
 * putui - formats unsigned int
 * @arg: argument list
 * Return: byte count
*/

int _putui(va_list arg)
{
	int num;
	int count = 0;
	int temp, digits, digit, divisor;
	int i, j;

	num = va_arg(arg, int);

	if (num < 0)
	{
		num = num * -1;
	}

	temp = num;
	digits = 0;

	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	temp = num;
	for (i = 0; i < digits; i++)
	{
		divisor = 1;
		for (j = i + 1; j < digits; j++)
		{
			divisor *= 10;
		}
		digit = (temp / divisor) % 10;
		realchar('0' + digit);
		count++;
	}
	return (count);
}
