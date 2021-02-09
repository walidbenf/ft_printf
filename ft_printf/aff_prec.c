/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:32:59 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:33:03 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_s_no_precision(int len, char *str, t_print *arg)
{
	char space;

	space = (!arg->zero ? ' ' : '0');
	if (len < arg->width)
	{
		arg->precision = arg->width - len;
	}
	else
		arg->precision = 0;
	if (!(arg->minus))
	{
		ft_put_fd(space, 1, arg->precision, arg);
		ft_putstr_fd(str, 1, len, arg);
	}
	else
	{
		ft_putstr_fd(str, 1, len, arg);
		ft_put_fd(space, 1, arg->precision, arg);
	}
}

void	output_s_with_precision(int len, char *str, t_print *arg)
{
	char space;

	space = (!arg->zero ? ' ' : '0');
	if ((len < arg->precision || arg->precision < 0))
		arg->precision = len;
	if (arg->width < arg->precision)
		arg->width = arg->precision;
	if (!arg->minus)
	{
		ft_put_fd(space, 1, arg->width - arg->precision, arg);
		ft_putstr_fd(str, 1, arg->precision, arg);
	}
	else
	{
		ft_putstr_fd(str, 1, arg->precision, arg);
		ft_put_fd(space, 1, arg->width - arg->precision, arg);
	}
}
