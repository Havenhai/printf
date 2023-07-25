#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cr_i;
	int width = 0;

	for (cr_i = *i + 1; format[cr_i] != '\0'; cr_i++)
	{
		if (is_digit(format[cr_i]))
		{
			width *= 10;
			width += format[cr_i] - '0';
		}
		else if (format[cr_i] == '*')
		{
			cr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cr_i - 1;

	return (width);
}
