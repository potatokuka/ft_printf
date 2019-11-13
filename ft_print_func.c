/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_func.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:18:54 by greed          #+#    #+#                */
/*   Updated: 2019/11/13 15:10:47 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "stdarg.h"

void		ft_print_char(t_conv *conv, va_list a_list, int *c_print)
{
	int			c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
			conv->precision = 1;
	if (conv->left)
	{
		*c_print += 1;
		ft_putchar_fd(c, 1);
	}
	ft_pad_width(conv->width, conv->precision, ' ', c_print);
	if (!(conv->left))
	{
		*c_print += 1;
		ft_putchar_fd(c, 1);
	}
}

void		ft_print_string(t_conv *conv, va_list a_list, int *c_print)
{
	char		*str;
	int			len;

	str = va_arg(a_list, char *);
	if (!(str))
		str = "(null)";
	len = ft_strlen(str);
	// printf("%d", conv->precision);
	// printf("%d", conv->width);
	if (conv->precision == -2 || conv->precision > len)
			conv->precision = len;
	// printf("%d", conv->precision);
	// printf("%d", conv->width);
	if (conv->left)
			ft_putstr_c_fd(str, 1, conv->precision, c_print);
	ft_pad_width(conv->width, conv->precision, ' ', c_print);
	if (!(conv->left))
		ft_putstr_c_fd(str, 1, conv->precision, c_print);
}

// void		ft_print_int(t_conv *conv, va_list a_list, int *c_print)
// {
// 	unsigned int		res;
// 	unsigned int		num;

// 	num = va_arg(a_list, int);
// 	if (!(num))
// 		res = 0;
// 	if (num < 0)
// 	{
// 		ft_putchar_fd('-', 1);
// 		res = (unsigned int)(num * -1);
// 	}
// 	else
// 		res = (unsigned int)num;
// 	if (res >= 10)
// 		ft_print_int(conv, res / 10, c_print);
// 	ft_putchar_c_fd((char)(res % 10 + '0'), 1, c_print);
// }

// void	ft_putchar_n_fd(char c, int fd, int *c_print)
// {
// 	ft_putchar_fd(c, fd);
// 	*c_print = *c_print + 1;
// }