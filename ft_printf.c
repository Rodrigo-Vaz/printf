/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolucas- <rolucas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:16:52 by rolucas-          #+#    #+#             */
/*   Updated: 2025/07/07 22:58:28 by rolucas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int print_char(char c)
{
	return (write(1, &c, 1));
}
int	print_str(char *s)
{
	int	count;

	count = 0;
	while(*s)
	{
		count += print_char(*s++);
	}
	return (count);
}
long 	putnbr(long n)
{
	int	count;

	count = 1;
	if (n < INT_MIN || n > INT_MAX)
		return 0;
	if (n == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n > 0)
	{
		putnbr(n / 10);
		count += print_char(n % 10 + '0');
	}
	return (count + 1);		
}
int print_format (char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += putnbr(va_arg(ap, int));
	return (count);
}


int	ft_printf(const char *format, ...) // The function signature indicates that it takes a format string and a variable number of arguments, which is the three dots.
{

	va_list ap;
	int count;

	if (!format)
		return(-1);
	va_start(ap, format); // Initializes the variable argument list with the last named parameter (format).
	count = 0; // Initialize the count of characters written to zero.
	while (*format != '\0') // Loop through each character in the format string until the null terminator is reached.
	{
		if (*format == '%') // If the current character is a format specifier.
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end (ap);
	return count;
}
int main()
{
	int count;

	count = printf("Hello %d\n", 123);
	ft_printf("The chars written are %d\n", count);
}