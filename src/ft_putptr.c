/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:11 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/18 18:51:40 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putpointer(uintptr_t value)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (value >= 16)
	{
		len += ft_putpointer(value / 16);
		len += ft_putpointer(value % 16);
	}
	else
		len += ft_putchar(hex[value]);
	return (len);
}

int	ft_putptr(uintptr_t value)
{
	int	len;

	len = 0;
	len = write(1, "0x", 2);
	if (value == 0)
		len += ft_putchar('0');
	else
		len += ft_putpointer(value);
	return (len);
}
