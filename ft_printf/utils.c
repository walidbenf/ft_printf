/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:35:54 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:57 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0);
}

int		ft_atoi(char *str)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res <= -2147483648 && sign == -1)
			return (0);
	}
	return (res * sign);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	int				i;

	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
