/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:34:53 by wben-far          #+#    #+#             */
/*   Updated: 2021/02/09 15:35:00 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_print
{
	va_list	output;
	char	*string;
	int		zero;
	int		minus;
	int		precision;
	int		width;
	int		res_len;
	long	num;
}				t_print;

int				ft_printf(const char *str, ...);
void			output_flag_c(t_print *arg);
int				ft_strlen(char *str);
void			output_flag_s(t_print *arg);
void			output_flag_proc(t_print *arg);
void			ft_putchar_fd(char c, int fd, t_print *arg);
void			output_flag_s(t_print *arg);
void			output_flag_proc(t_print *arg);
void			output_flag_c(t_print *arg);
void			flag_precision(t_print *arg);
void			ft_width(t_print *arg);
void			ft_put_fd(char s, int fd, int size, t_print *arg);
int				ft_atoi(char *str);
void			output_s_no_precision(int len, char *str, t_print *arg);
void			output_s_with_precision(int len, char *str, t_print *arg);
void			output_number_di(t_print *arg, int base, int upper);
void			output_number_ux(t_print *arg, int base, int upper);
void			output_pointer(t_print *arg, int base);
long			ft_num_len(long n, int base);
void			ft_putchar_fd(char c, int fd, t_print *arg);
void			ft_putnbr_fd(long n, size_t base, int up, t_print *arg);
void			ft_put_fd(char s, int fd, int size, t_print *arg);
void			ft_putstr_fd(char *s, int fd, int len, t_print *arg);
void			null_pointer(t_print *arg);
long			ft_num_len(long n, int base);
void			ft_num_minus(t_print *arg);
void			ft_num(t_print *arg, long num);
void			zeroing_arg(t_print *arg);
void			ft_pars(t_print *arg);
void			*ft_memchr(void *s, int c, size_t n);
void			ft_null_pointer(t_print *arg);

#endif
