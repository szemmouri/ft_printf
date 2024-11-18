/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:02 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/18 18:50:41 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_type(const char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == '%')
		counter += ft_putchar('%');
	else if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		counter += ft_putptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		counter += ft_putid(va_arg(args, int));
	else if (c == 'u')
		counter += put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_puthex(va_arg(args, unsigned int), c);
	else if (c != 0)
	{
		counter += ft_putchar('%');
		counter += ft_putchar(c);
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		tmp;
	int		count;

	count = 0;
	i = 0;
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			tmp = ft_putchar(format[i]);
		else
			tmp = ft_type(format[++i], args);
		if (tmp == -1)
			return (-1);
		else
			count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
