/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:35:25 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:28 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_minus(t_print *arg)
{
	ft_put_fd('0', 1, 1, arg);
	ft_put_fd('x', 1, 1, arg);
	ft_put_fd('0', 1, arg->precision, arg);
	ft_put_fd(' ', 1, arg->width - arg->precision - 2, arg);
}

void	null_no_minus(t_print *arg)
{
	ft_put_fd(' ', 1, arg->width - arg->precision - 2, arg);
	ft_put_fd('0', 1, 1, arg);
	ft_put_fd('x', 1, 1, arg);
	ft_put_fd('0', 1, arg->precision, arg);
}

void	null_pointer(t_print *arg)
{
	if (!arg->width)
		arg->width = 2;
	if (arg->precision < 0)
		arg->precision = 1;
	if (arg->width < arg->precision + 2)
		arg->width = arg->precision + 2;
	((arg->minus == 1) ? null_minus(arg) : null_no_minus(arg));
}
