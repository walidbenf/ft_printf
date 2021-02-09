/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:33:11 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:33:14 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_num_len(long n, int base)
{
	long	len;

	len = 0;
	while (n > base - 1 || n < -(base - 1))
	{
		len++;
		n /= base;
	}
	len++;
	if (n < 0)
		len++;
	return (len);
}

void	ft_num_minus(t_print *arg)
{
	if (arg->num < 0)
	{
		ft_putchar_fd('-', 1, arg);
		arg->num = -(arg->num);
	}
}

void	ft_num(t_print *arg, long num)
{
	if (num < 0)
	{
		arg->precision++;
		if (arg->width < arg->precision)
			arg->width++;
	}
}
