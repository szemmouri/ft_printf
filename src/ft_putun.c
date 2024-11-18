/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:15:53 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/18 18:46:28 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_unsigned(unsigned int number)
{
	int	count;

	count = 0;
	if (number < 10)
	{
		count++;
		ft_putchar(number + '0');
		return (count);
	}
	count += put_unsigned(number / 10);
	count += put_unsigned(number % 10);
	return (count);
}
