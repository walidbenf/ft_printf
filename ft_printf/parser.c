/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:35:32 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:36 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_print *arg)
{
	arg->zero = 1;
	arg->string++;
}

void	flag_minus(t_print *arg)
{
	arg->minus = 1;
	arg->string++;
}

void	check_type(t_print *arg)
{
	if (*arg->string == 'c')
		output_flag_c(arg);
	if (*arg->string == 's')
		output_flag_s(arg);
	if (*arg->string == 'p')
		output_pointer(arg, 16);
	if (*arg->string == 'd' || *arg->string == 'i')
		output_number_di(arg, 10, 0);
	if (*arg->string == 'u')
		output_number_ux(arg, 10, 0);
	if (*arg->string == 'x')
		output_number_ux(arg, 16, 0);
	if (*arg->string == 'X')
		output_number_ux(arg, 16, 1);
	if (*arg->string == '%')
		output_flag_proc(arg);
}

void	ft_pars(t_print *arg)
{
	while (*arg->string != '\0')
	{
		while (*arg->string == '0' || *arg->string == '-' ||
		*arg->string == '*' || *arg->string == '.' ||
		(*arg->string >= '0' && *arg->string <= '9'))
		{
			if (*arg->string == '0' || *arg->string == '-')
				((*arg->string == '0') ? flag_zero(arg) : flag_minus(arg));
			if (*arg->string == '*' || *arg->string == '.' ||
			(*arg->string >= '0' && *arg->string <= '9'))
				((*arg->string == '.') ? flag_precision(arg) : ft_width(arg));
		}
		if ((ft_memchr("spcdiuxX%", *arg->string, 9)))
		{
			if ((arg)->minus == 1)
				(arg)->zero = 0;
			check_type(arg);
			(arg->string)++;
			break ;
		}
		else
			return ;
	}
}

void	zeroing_arg(t_print *arg)
{
	arg->minus = 0;
	arg->zero = 0;
	arg->precision = -1;
	arg->width = 0;
}
