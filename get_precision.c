#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cr_i = *i + 1;
	int preci = -1;

	if (format[cr_i] != '.')
		return (preci);

	preci = 0;

	for (cr_i += 1; format[cr_i] != '\0'; cr_i++)
	{
		if (is_digit(format[cr_i]))
		{
			preci *= 10;
			preci += format[cr_i] - '0';
		}
		else if (format[cr_i] == '*')
		{
			cr_i++;
			preci = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cr_i - 1;

	return (preci);
}
