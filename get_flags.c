#include "main.h"

/**
 * get_flags - calculate active flags
 * @format: formatted strings
 * @i: accepts parameters
 * Return: flags:
 */
int get_flags(const char *format, int *i)
{
	int j, curi;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curi = *i + 1; format[curi] != '\0'; curi++)
	{
		for (j = 0; FLAGS_CH[J] != '\0'; j++)
			if (format[curi] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curi - 1;

	return (flags);
}
