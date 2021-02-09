/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:36:06 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:36:11 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision(t_print *arg)
{
	if (*(++(arg->string)) == '*')
	{
		arg->precision = (va_arg(arg->output, int));
		arg->string++;
	}
	else
	{
		arg->precision = ((ft_atoi(arg->string)));
		while ((*(arg->string) >= '0' && (*(arg->string) <= '9')))
		{
			arg->string++;
		}
	}
}

void	ft_width(t_print *arg)
{
	if (*arg->string == '*')
	{
		arg->width = (va_arg(arg->output, int));
		arg->string++;
		if (arg->width < 0)
		{
			arg->width = -arg->width;
			arg->minus = 1;
		}
	}
	else
	{
		arg->width = ((ft_atoi(arg->string)));
		while (((*arg->string) >= '0' && (*arg->string) <= '9'))
			arg->string++;
	}
}
