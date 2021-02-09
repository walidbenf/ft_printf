/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:32:46 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:32:52 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_print *arg)
{
	write(fd, &c, 1);
	arg->res_len++;
}

void	ft_putnbr_fd(long n, size_t base, int up, t_print *arg)
{
	char			c;
	unsigned long	num;
	char			upper;

	upper = (up == 1) ? 'A' : 'a';
	if (n < 0)
	{
		write(1, "-", 1);
		arg->res_len++;
		n = -n;
	}
	num = (unsigned long)n;
	if (num >= base)
	{
		ft_putnbr_fd(num / base, base, up, arg);
		c = (num % base) + (num % base > 9 ? upper - 10 : '0');
		write(1, &c, 1);
		arg->res_len++;
	}
	if (num >= 0 && num <= base - 1)
	{
		c = num + (num % base > 9 ? upper - 10 : '0');
		write(1, &c, 1);
		arg->res_len++;
	}
}

void	ft_put_fd(char s, int fd, int size, t_print *arg)
{
	while (size)
	{
		write(fd, &s, 1);
		arg->res_len++;
		size--;
	}
}

void	ft_putstr_fd(char *s, int fd, int len, t_print *arg)
{
	write(fd, s, len);
	arg->res_len = arg->res_len + len;
}
