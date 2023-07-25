#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cr_i = *i + 1;
	int si = 0;

	if (format[cr_i] == 'l')
		si = S_LONG;
	else if (format[cr_i] == 'h')
		si = S_SHORT;

	if (si == 0)
		*i = cr_i - 1;
	else
		*i = cr_i;

	return (si);
}
