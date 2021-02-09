/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:33:37 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:33:40 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_print arg;

	arg.res_len = 0;
	arg.string = (char*)str;
	va_start(arg.output, str);
	while (*arg.string != '\0')
	{
		while (*arg.string != '%' && *arg.string != '\0')
		{
			write(1, arg.string, 1);
			(arg.string)++;
			(arg.res_len)++;
		}
		if (*arg.string == '%')
			(arg.string)++;
		zeroing_arg(&arg);
		ft_pars(&arg);
	}
	va_end(arg.output);
	return (arg.res_len);
}
