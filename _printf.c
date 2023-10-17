#include "main.h"

void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int i;
	int prntd = 0;
	int prntd_chars = 0;
	int flags = 0;
	int width = 0;
	int precision = 0;
	int size = 0;
	int buff_index = 0;

	va_list ls_of_args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ls_of_args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		buffer[buff_index++] = format[i];
		if (buff_index == BUFF_SIZE)
			print_buffer(buffer, &buff_index);
		prntd_chars++;
	}
	else
	{
		print_buffer(buffer, &buff_index);
		flags = get_flags(format, &i);
		width = get_width(format, &i, ls_of_args);
		precision = get_precision(format, &i, ls_of_args);
		size = get_size(formt, &i);
		++i;
		prntd = handle_print(format, &i, ls_of_args, buffer, flags,
				width, precision, size);
	}
}
print_buffer(buffer, &buff_index);

va_end(ls_of_args);
return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: characters
 * @buff_index: Index of each char
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
