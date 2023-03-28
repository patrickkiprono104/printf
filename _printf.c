#include "main.h"

int _putchar(char c);
/**
 * _printf - prints formatted output to stdout
 *
 * @format: format string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				for (i = 0; s[i] != '\0'; i++)
				{
					_putchar(s[i]);
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_ends(args);
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: on Success 1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
