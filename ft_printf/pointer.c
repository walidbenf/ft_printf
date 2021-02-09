/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:35:40 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:43 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_no_precision(t_print *arg, int base, int len, long num)
{
	char space;

	if (arg->zero)
		space = '0';
	else
		space = ' ';
	if (len + 2 < arg->width)
		arg->precision = arg->width - len - 2;
	else
		arg->precision = 0;
	if (arg->minus)
	{
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
		ft_putnbr_fd(num, base, 0, arg);
		ft_put_fd(space, 1, arg->precision, arg);
	}
	else
	{
		ft_put_fd(space, 1, arg->precision, arg);
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
		ft_putnbr_fd(num, base, 0, arg);
	}
}

void	ft_pointer_with_precision(t_print *arg, int base, int len, long num)
{
	if (arg->precision < len || arg->precision < 0)
		arg->precision = len;
	if (arg->width > arg->precision)
		arg->width -= 2;
	if (arg->width < arg->precision)
		arg->width = arg->precision;
	if (!arg->minus)
	{
		ft_put_fd(' ', 1, arg->width - arg->precision, arg);
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
		ft_put_fd('0', 1, arg->precision - len, arg);
		ft_putnbr_fd(num, base, 0, arg);
	}
	else
	{
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
		ft_put_fd('0', 1, arg->precision - len, arg);
		ft_putnbr_fd(num, base, 0, arg);
		ft_put_fd(' ', 1, arg->width - arg->precision, arg);
	}
}

void	ft_output_pointer(t_print *arg, int num)
{
	if (!num && arg->precision == 0 && arg->minus == 0 && arg->width == 0)
	{
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
	}
	if (!num && arg->precision == 0 && arg->minus == 1 && arg->width != 0)
	{
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
		ft_put_fd(' ', 1, arg->width - 2, arg);
	}
	if (!num && arg->precision == 0 && arg->minus == 0 && arg->width != 0)
	{
		ft_put_fd(' ', 1, arg->width - 2, arg);
		ft_put_fd('0', 1, 1, arg);
		ft_put_fd('x', 1, 1, arg);
	}
}

void	output_pointer(t_print *arg, int base)
{
	long	num;
	int		len;

	num = va_arg(arg->output, unsigned long);
	len = ft_num_len(num, base);
	if (arg->precision < 0)
		ft_pointer_no_accuracy(arg, base, len, num);
	else
	{
		if (!num && arg->precision == 0)
			ft_output_pointer(arg, num);
		else if (!num && arg->precision != 0)
			ft_null_pointer(arg);
		else
			ft_pointer_with_accuracy(arg, base, len, num);
	}
}
