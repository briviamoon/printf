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
	long unsigned int i;

	FunctionFormats formatFunctions[] = {
		{_putint, 'd'},
		{_putint, 'i'},
		{_putchar, 'c'},
		{_putui, 'u',},
		{_putstr, 's'},
	};

	count = 0;
	for (i = 0; i < sizeof(formatFunctions) / sizeof(formatFunctions[0]); i++)
	{
		if (formatSpecifier == formatFunctions[i].specifierLEtter)
		{
			count += formatFunctions[i].function(arg);
			break;
		}
	}
	return (count);
}
