#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
 * _printf - produces output according to a format.
 * @format: this is a character string composed of zero or more directives.
 * Return: always return zero.
 */
int _printf(const char *format, ...)
{
	int length;
	const char *string;
	va_list args;

	va_start(args, format);
	length = 0;
	for (string = format; *string != '\0'; string++)
	{
		if (*string != '%')
		{
			length += printf("%c", *string);
			continue;
		}
		string++;
		switch (*string)
		{
			case 'c':
				length += printf("%c", va_arg(args, int));
				break;
			case 's':
				length += printf("%s", va_arg(args, char *));
				break;
			case '%':
				length += printf("%%");
				break;
			default:
				length += printf("%%%c", *string);
		}
	}
	va_end(args);
	return (length);
}
