#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: format string containing zero or more directives
 * @...: variable number of arguments to print
 *
 * Return: number of characters printed (excluding terminating null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _printstr(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += _printnum(va_arg(args, int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
			format++;
		}
		else
			count += _putchar(*format++);
	}

	va_end(args);
	return (count);
}

/**
 * _printstr - prints a string to stdout
 * @str: string to print
 *
 * Return: number of characters printed (excluding terminating null byte)
 */
int _printstr(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
		count += _putchar(*str++);

	return (count);
}

/**
 * _printnum - prints a number to stdout
 * @num: number to print
 *
 * Return: number of characters printed (excluding terminating null byte)
 */
int _printnum(int num)
{
	unsigned int abs_val, digit, count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		abs_val = -num;
	}
	else
		abs_val = num;

	if (abs_val / 10)
		count += _printnum(abs_val / 10);

	digit = abs_val % 10;
	count += _putchar(digit + '0');

	return (count);
}
