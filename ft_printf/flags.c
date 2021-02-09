/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:33:26 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:33:29 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_flag_s(t_print *arg)
{
	int		len;
	char	*str;

	str = va_arg(arg->output, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (arg->precision < 0)
		output_s_no_precision(len, str, arg);
	else
		output_s_with_precision(len, str, arg);
}

void	output_flag_proc(t_print *arg)
{
	char c;
	char space;

	c = '%';
	if (arg->zero)
		space = '0';
	else
		space = ' ';
	if (!arg->width)
		arg->width = 1;
	if (arg->minus == 1)
	{
		ft_putchar_fd(c, 1, arg);
		ft_put_fd(space, 1, (arg->width - 1), arg);
	}
	else
	{
		ft_put_fd(space, 1, (arg->width - 1), arg);
		ft_putchar_fd(c, 1, arg);
	}
}

void	output_flag_c(t_print *arg)
{
	char c;
	char space;

	c = va_arg(arg->output, int);
	if (arg->zero)
		space = '0';
	else
		space = ' ';
	if (!arg->width)
		arg->width = 1;
	if (arg->minus == 1)
	{
		ft_putchar_fd(c, 1, arg);
		ft_put_fd(space, 1, (arg->width - 1), arg);
	}
	else
	{
		ft_put_fd(space, 1, (arg->width - 1), arg);
		ft_putchar_fd(c, 1, arg);
	}
}
