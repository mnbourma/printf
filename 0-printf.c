#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - produces output according to a format.
 * @format: this is a character string composed of zero or more directives.
 * Return: always return zero.
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, format);
	for (i = 0; i < (int)strlen(format); i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printf("%c", va_arg(args, int));
					break;
				case 's':
					printf("%s", va_arg(args, char *));
					break;
				case '%':
					printf("%%%%");
					break;
				default:
					printf("%%");
			}
		}
	}
	va_end(args);
	return (0);
}
