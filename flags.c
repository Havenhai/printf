#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, cr_i;
	int flags = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cr_i = *i + 1; format[cr_i] != '\0'; cr_i++)
	{
		for (j = 0; FLAG_CH[j] != '\0'; j++)
			if (format[cr_i] == FLAG_CH[j])
			{
				flags |= FLAG_ARR[j];
				break;
			}

		if (FLAG_CH[j] == 0)
			break;
	}

	*i = cr_i - 1;

	return (flags);
}
