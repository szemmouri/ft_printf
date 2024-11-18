/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:08 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/17 15:02:54 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static int	ft_numlen(int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putid(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_numlen(num));
}
