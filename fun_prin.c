#include "main.h"
/**
 * _printf - function prints arguments depend on different format
 * @format: string passed
 *
 * Return: intiger of sting length
 */
int _printf(const char *format, ...)
{
	int i = 0, j  = 0;
	int k;
	va_list valist;
	char buff[BUFSIZ];

	va_start(valist, format);

	while (format && format[i])
	{
		if (format[i] != '\0')
		{
			i++;
			switch (format[i] == '%')
			{
			case 'c':
			{
				 buff[j] = (char)(va_arg(valist, int));
				 j++, break;
			}
			case 's':
			{
				char *f = va_arg(valist, char*);

				k = 0;
				while (f[k] != '\0')
				{
					buff[j] = f[k];
					j++;
					k++;
				}
				break;
			}
			case '%':
			{
				buff[j] = format[i];
				j++;
				break;

			}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, buff, j);
	return (j);
}
