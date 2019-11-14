/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 09:35:37 by greed          #+#    #+#                */
/*   Updated: 2019/11/14 15:45:31 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stdarg.h>

typedef struct		s_conv
{
	int				left;
	int				hash;
	int				padzero;
	int				width;
	int				precision;
	int				numlen;
	char			blank;
	char			type;
	char			pos;
	char			len;
	char			hassign;
	char			neg;
}					t_conv;
typedef void	(*t_cfunc)(t_conv *, va_list, int *);

int			ft_printf(const char *input, ...);
void		ft_putnbr_count_fd(int n, int fd, t_conv *conv, int *input_len);
int			ft_nbr_size(int i);
void		ft_flag_check(const char **input, t_conv *conv);
void		ft_find_type(const char **input, t_conv *conv);
void		ft_flag_vars_set(t_conv *conv);
void		ft_print_char(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_string(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_pointer(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_int(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_uint(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_hex_lower(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_hex_upper(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_count(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_float(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_science(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_comp_float(t_conv *conv, va_list a_list, int *c_print);
void		ft_print_percent(t_conv *conv, va_list a_list, int *c_print);
void		ft_pad_width(int width, int precision, int pad, int *c_print);
void		ft_putstr_c_fd(char *str, int fd, int n, int *c_print);
void		ft_putchar_c_fd(char c, int fd, int *c_print);
void		ft_precision_check(const char **input, t_conv *conv);
void		ft_putnbr_c_fd(int n, int fd, t_conv *conv, int *c_print);
int			ft_nbr_size(int i);
void		ft_conv_dec(t_conv *conv, va_list a_list, int *c_print);
void		ft_trunc_width(int n, int fd, t_conv *conv, int *c_print);
void		ft_print_sign(int fd, t_conv *conv, int *c_print);
#endif
