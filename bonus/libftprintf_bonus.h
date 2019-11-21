/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf_bonus.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 09:35:37 by greed          #+#    #+#                */
/*   Updated: 2019/11/21 14:18:42 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_conv
{
	int				left;
	int				hash;
	int				padzero;
	int				width;
	int				precision;
	int				numlen;
	int				size;
	char			type;
	char			sign;
	int				len;
	char			hassign;
	char			neg;
	int				count;
	unsigned int	u_numlen;
}					t_conv;
typedef void	(*t_cfunc)(t_conv *, va_list, int *);
typedef void	(*t_lfunc)(t_conv *, va_list, int *);

int					ft_printf(const char *input, ...);
void				ft_putnbr_count_fd(int n, int fd, t_conv *conv, int *lv);
int					ft_nbr_size(int num);
void				ft_flag_check(const char **input, t_conv *conv);
void				ft_find_type(const char **input, t_conv *conv);
void				ft_flag_vars_set(t_conv *conv);
void				ft_print_char(t_conv *conv, va_list a_list, int *lv);
void				ft_print_string(t_conv *conv, va_list a_list, int *lv);
void				ft_print_pointer(t_conv *conv, va_list a_list, int *lv);
void				ft_print_int(t_conv *conv, va_list a_list, int *lv);
void				ft_print_uint(t_conv *conv, va_list a_list, int *lv);
void				ft_print_hex_lower(t_conv *conv, va_list a_list, int *lv);
void				ft_print_hex_upper(t_conv *conv, va_list a_list, int *lv);
void				ft_print_count(t_conv *conv, va_list a_list, int *lv);
void				ft_print_percent(t_conv *conv, va_list a_list, int *lv);
void				ft_pad_width(int width, int precision, int pad, int *lv);
void				ft_putstr_c_fd(char *str, int fd, int n, int *lv);
void				ft_putchar_c_fd(char c, int fd, int *lv);
void				ft_precision_check(const char **input, t_conv *conv);
void				ft_putnbr_c_fd(int n, int fd, t_conv *conv, int *lv);
void				ft_conv_dec(t_conv *conv, va_list a_list, int *lv);
void				ft_trunc_width(int n, int fd, t_conv *conv, int *lv);
void				ft_print_sign(int fd, t_conv *conv, int *lv);
void				ft_conv_int(t_conv *conv, int *num);
void				ft_intres_c_fd(int num, int *lv);
void				ft_print_uint(t_conv *conv, va_list a_list, int *lv);
unsigned int		ft_uint_size(unsigned int num);
void				ft_conv_uint(t_conv *conv, unsigned int num);
void				ft_u_intres_c_fd(unsigned int num, int *lv);
void				ft_print_x(t_conv *conv, va_list a_list, int *lv);
unsigned int		ft_x_size(unsigned int num);
void				ft_conv_x(t_conv *conv, unsigned int *num);
void				ft_x_res_c_fd(unsigned int num, int *lv);
void				ft_upx_res_c_fd(unsigned int num, int *lv);
void				ft_print_up_x(t_conv *conv, va_list a_list, int *lv);
void				ft_print_pct(t_conv *conv, va_list a_list, int *lv);
int					ft_valid_arg(const char **input, t_conv *conv);

/*
** THIS IS STUFF FOR SIZE BONUS
*/
void				ft_size_num(t_conv *conv, va_list a_list, int *lv);

/*
** Links for size
*/
void				ft_uint_link(t_conv *conv, va_list a_list, int *lv);
void				ft_int_link(t_conv *conv, va_list a_list, int *lv);
void				ft_x_link(t_conv *conv, va_list a_list, int *lv);
void				ft_up_x_link(t_conv *conv, va_list a_list, int *lv);

/*
** LL
*/
void				ft_conv_ll_int(t_conv *conv, long long int num);
long long int		ft_ll_nbr_size(long long int num);
void				ft_llint_c_fd(long long int num, int *lv);
void				ft_ll_num(t_conv *conv, va_list a_list, int *lv);

/*
** xX
*/

void				ft_print_ll_x(t_conv *conv, va_list a_list, int *lv);
int					ft_x_ll_size(unsigned long long num);
void				ft_x_res_ll_c_fd(unsigned long long num, int *lv);
void				ft_conv_ll_x(t_conv *conv, unsigned long long *num);
void				ft_ll_x(t_conv *conv, va_list a_list, int *lv);
void				ft_print_ll_up_x(t_conv *conv, va_list a_list, int *lv);
void				ft_upx_res_ll_c_fd(unsigned long long num, int *lv);

/*
** LLU
*/

void				ft_llu(t_conv *conv, va_list a_list, int *lv);
void				ft_llu_num(t_conv *conv, va_list a_list, int *lv);
void				ft_lluint_c_fd(unsigned long long num, int *lv);
int					ft_llu_nbr_size(unsigned long long num);
void				ft_conv_llu_int(t_conv *conv, unsigned long long num);

/*
** Pointers
*/

void				ft_print_pointer(t_conv *conv, va_list a_list, int *lv);
unsigned long		ft_ptr_size(unsigned long ptr);
void				ft_conv_ptr(t_conv *conv, unsigned long ptr);
void				ft_ptr_res_fd(unsigned long ptr, int *lv);
#endif
