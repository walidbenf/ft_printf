/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:35:25 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:28 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_minus(t_print *var)
{
	ft_put_fd('0', 1, 1, var);
	ft_put_fd('x', 1, 1, var);
	ft_put_fd('0', 1, var->precision, var);
	ft_put_fd(' ', 1, var->width - var->precision - 2, var);
}

void	null_no_minus(t_print *var)
{
	ft_put_fd(' ', 1, var->width - var->precision - 2, var);
	ft_put_fd('0', 1, 1, var);
	ft_put_fd('x', 1, 1, var);
	ft_put_fd('0', 1, var->precision, var);
}

void	null_pointer(t_print *var)
{
	if (!var->width)
		var->width = 2;
	if (var->precision < 0)
		var->precision= 1;
	if (var->width < var->precision + 2)
		var->width = var->precision + 2;
	((var->minus == 1) ? null_minus(var) : null_no_minus(var));
}
