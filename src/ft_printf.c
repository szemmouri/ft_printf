/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:02 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/20 17:51:42 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_isvalid_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static int	ft_type(const char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		counter += ft_putptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		counter += ft_putid(va_arg(args, int));
	else if (c == 'u')
		counter += put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format);
		else
		{
			format++;
			if (*format == '\0')
				break ;
			if (ft_isvalid_type(*format))
				count += ft_type(*format, args);
			else
				count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
