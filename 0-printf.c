#include <stdarg.h>
#include <stdio.h>
/**
 * case - checks format cases.
 * @c: this is the format character.
 * Return: length of the formated string.
 */
int case(char c);
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
		}
		else
		{
			string++;
			length += case(*string);
		}
	}
	va_end(args);
	return (length);
}
/**
 * case - checks format cases.
 * @c: this is the format character.
 * Return: length of the formated string.
 */
int case(char c)
{
	int length;

	length = 0;
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
		case 'd':
			length += printf("%d", va_arg(args, int));
			break;
		case 'i':
			length += printf("%i", va_arg(args, int));
			break;
		case 'x':
			length += printf("%x", va_arg(args, int));
			break;
		default:
			length += printf("%%%c", *string);
	}
	return (length);
}
