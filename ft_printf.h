/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:22 by szemmour          #+#    #+#             */
/*   Updated: 2024/11/21 14:52:13 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>


// typedef struct {
//    unsigned int gp_offset;         // 8 bytes 6 args // hold the idx of the current int
//    unsigned int fp_offset;         // 16 bytes 6 args // hold the idx of the current flaot
//    void *overflow_arg_area;        // pointing to the first arg in stack
//    void *reg_save_area;            // pointing to the first arg in register
// } va_list;


int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putid(int num);
int	put_unsigned(unsigned int number);
int	ft_puthex(unsigned int value, const char c);
int	ft_putptr(unsigned long value);

#endif
