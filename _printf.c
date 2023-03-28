#include "main.h"

int _putchar(char c);

/**
 * _printf - prints formatted output to stdout
 *
 * @format: format string
 * @...: variadic arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int c = va_arg(args, int);

						_putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);

					if (s == NULL)
						s = "(nil)";
					while (*s != '\0')
					{
						_putchar(*s);
						count++;
						s++;
						}
						break;
					}
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					count++;
					_putchar(*format);
					count++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
