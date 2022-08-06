#include "main.h"
#include <stdlib.h>
/**
  * _printf - printf function
  * @format: list of argument types passed to the function
  *
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list parameter;
	int gen_counter;
	int num_character;

	num_character = 0;
	va_start(parameter, format);
	for (gen_counter = 0; format[gen_counter] != '\0'; gen_counter++)
	{
		if (format[gen_counter] == '%')
		{
			if (format[gen_counter + 1] == 'c')
			{
				num_character += character(parameter);
				gen_counter++;
			}
			else if (format[gen_counter + 1] == 's')
			{
				num_character += string_character(parameter);
				gen_counter++;
			}
			else if (format[gen_counter + 1 == 'd' || format[gen_counter] == 'i'])
			{
				num_character += print_digit(parameter);
				gen_counter++;
			}
			else if (format[gen_counter + 1] == '%')
			{
				_putchar('%');
				gen_counter++;
				num_character++;
			}
		}
		else
		{
			_putchar(format[gen_counter]);
			num_character++;
		}
	}
	va_end(parameter);
	return (num_character);
}
