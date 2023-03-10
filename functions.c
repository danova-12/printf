#include "main.h"
/**
 * _putchar - Write characteres
 * @c: input parameter
 *
 * Return: Writed character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printc - Print character
 * @list: input parameter
 *
 * Return: 1
 */
int printc(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
/**
 * print_string - Write string
 * @s: input parameter
 *
 * Return: k (number of bytes) or 6 (NULL)
 */
int print_string(va_list s)
{
	char *str;
	int k;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (k = 0; str[k] != '\0'; k++)
		{
			_putchar(str[k]);
		}
	}
	return (k);
}
/**
 * print_n - Print number
 * @n: input parameter to compute
 *
 * Return: count (number of bytes)
 */
int print_n(va_list n)
{

	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(n, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}
/**
 * print_b - print binary
 * @b: input parameter
 *
 * Return: number of bits
 */
int print_b(va_list b)
{
	int counter = 0, j;
	unsigned int array[32];
	unsigned int div;

	div = va_arg(b, int);
	if (div == 0)
	{
		_putchar('0');
		return (1);
	}
	while (div > 0)
	{
		array[counter] = div % 2;
		div = div / 2;
		counter++;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		_putchar('0' + array[j]);
	}
	return (counter);
}
