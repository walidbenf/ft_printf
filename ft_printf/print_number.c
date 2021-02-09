/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:35:47 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:50 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_with_precision(t_print *arg, int base, int upper, int len)
{
	if (len <= arg->precision)
		ft_num(arg, arg->num);
	if (arg->precision < len)
		arg->precision = len;
	if (arg->width < arg->precision)
		arg->width = arg->precision;
	if (!arg->minus)
	{
		ft_put_fd(' ', 1, arg->width - arg->precision, arg);
		ft_num_minus(arg);
		ft_put_fd('0', 1, (arg->precision - len), arg);
		ft_putnbr_fd(arg->num, base, upper, arg);
	}
	else
	{
		ft_num_minus(arg);
		ft_put_fd('0', 1, arg->precision - len, arg);
		ft_putnbr_fd(arg->num, base, upper, arg);
		ft_put_fd(' ', 1, arg->width - arg->precision, arg);
	}
}

void	num_no_precision(t_print *arg, int base, int upper, int len)
{
	char spase;

	if (arg->zero)
	{
		spase = '0';
		ft_num_minus(arg);
	}
	else
		spase = ' ';
	if (len < arg->width)
		arg->precision = arg->width - len;
	else
		arg->precision = 0;
	if (!arg->minus)
	{
		ft_put_fd(spase, 1, arg->precision, arg);
		ft_num_minus(arg);
		ft_putnbr_fd(arg->num, base, upper, arg);
	}
	else
	{
		ft_putnbr_fd(arg->num, base, upper, arg);
		ft_put_fd(spase, 1, arg->precision, arg);
	}
}

void	output_number_di(t_print *arg, int base, int upper)
{
	int len;

	arg->num = va_arg(arg->output, int);
	len = ft_num_len(arg->num, base);
	if (arg->precision < 0)
	{
		num_no_precision(arg, base, upper, len);
	}
	else
	{
		if (!arg->num && arg->precision == 0)
			ft_put_fd(' ', 1, arg->width, arg);
		else
			num_with_precision(arg, base, upper, len);
	}
}

void	output_number_ux(t_print *arg, int base, int upper)
{
	long len;

	arg->num = va_arg(arg->output, unsigned int);
	len = ft_num_len(arg->num, base);
	if (arg->precision < 0)
	{
		num_no_precision(arg, base, upper, len);
	}
	else
	{
		if (!arg->num && arg->precision == 0)
			ft_put_fd(' ', 1, arg->width, arg);
		else
			num_with_precision(arg, base, upper, len);
	}
}
