/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolucas- <rolucas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:16:52 by rolucas-          #+#    #+#             */
/*   Updated: 2025/06/25 21:51:07 by rolucas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...) // The function signature indicates that it takes a format string and a variable number of arguments, which is the three dots.
{

	va_list ap;
	int count;

	va_start(ap, format); // Initializes the variable argument list with the last named parameter (format).
	count = 0; // Initialize the count of characters written to zero.
	while (*format != '\0') // Loop through each character in the format string until the null terminator is reached.
	{
		if (*format == '%') // If the current character is a format specifier.

	)
int main()
{
	int count;

	count = ft_printf("Hello %s/n", "Rodrigo");
	ft_printf("The chars written are %d\n", count);
}