/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_func.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:18:54 by greed          #+#    #+#                */
/*   Updated: 2019/11/12 17:18:14 by greed         ########   odam.nl         */
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
	if (conv->precision == -2 || conv->precision > len)
			conv->precision = len;
	if (conv->left)
			ft_putstr_c_fd(str, 1, conv->precision, c_print);
	ft_pad_width(conv->width, conv->precision, ' ', c_print);
	if (!(conv->left))
		ft_putstr_c_fd(str, 1, conv->precision, c_print);
}