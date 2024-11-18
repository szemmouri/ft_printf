/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:05 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/18 18:45:46 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hexlen(unsigned int value)
{
	int	len;

	if (value == 0)
		return (1);
	len = 0;
	while (value > 0)
	{
		value /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthx(unsigned int value, char c)
{
	if (value >= 16)
	{
		ft_puthx(value / 16, c);
		ft_puthx(value % 16, c);
	}
	else
	{
		if (value <= 9)
			ft_putchar(value + '0');
		else
		{
			if (c == 'X')
				ft_putchar(value - 10 + 'A');
			else
				ft_putchar(value - 10 + 'a');
		}
	}
}

int	ft_puthex(unsigned int value, const char c)
{
	if (value == 0)
		ft_putchar('0');
	else
		ft_puthx(value, c);
	return (ft_hexlen(value));
}
