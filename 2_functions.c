#include "main.h"
/**
 * print_x - print hexadecimal numbers
 * in lowercase
 * @x: input parameter
 *
 * Return: number of bits
 */
int print_x(va_list x)
{
	int counter = 0, j;
	unsigned int array[8];
	unsigned int div;

	div = va_arg(x, int);
	if (div == 0)
	{
		_putchar('0');
		return (1);
	}
	while (div > 0)
	{
		array[counter] = div % 16;
		div = div / 16;
		counter++;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		if (array[j] <= 9)
			_putchar('0' + array[j]);
		else
			_putchar('a' + (array[j] - 10));
	}
	return (counter);
}
/**
 * print_X - print hexadecimal numbers
 * in uppercase
 * @X: input parameter
 *
 * Return: number of bits
 */
int print_X(va_list X)
{
	int counter = 0, j;
	unsigned int array[8];
	unsigned int div;

	div = va_arg(X, int);
	if (div == 0)
	{
		_putchar('0');
		return (1);
	}
	while (div > 0)
	{
		array[counter] = div % 16;
		div = div / 16;
		counter++;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		if (array[j] <= 9)
			_putchar('0' + array[j]);
		else
			_putchar('A' + (array[j] - 10));
	}
	return (counter);
}
/**
 * print_o - print octal numbers
 * @o: input parameter
 *
 * Return: number of bits
 */
int print_o(va_list o)
{
	int counter = 0, j;
	unsigned int array[11];
	unsigned int div;

	div = va_arg(o, int);
	if (div == 0)
	{
		_putchar('0');
		return (1);
	}
	while (div > 0)
	{
		array[counter] = div % 8;
		div = div / 8;
		counter++;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		_putchar('0' + array[j]);
	}
	return (counter);
}
/**
 * print_u - Print number
 * @u: input parameter to compute
 *
 * Return: count (number of bytes)
 */
int print_u(va_list u)
{

	unsigned int number;
	unsigned int aux_variable, base;
	int counter;

	counter = 0;
	number = va_arg(u, int);
	if (number <= 9)
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
