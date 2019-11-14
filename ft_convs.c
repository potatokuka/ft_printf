/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 11:53:05 by greed          #+#    #+#                */
/*   Updated: 2019/11/14 15:55:27 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_conv_dec(t_conv *conv, va_list a_list, int *c_print)
{
	int	num;

	num = va_arg(a_list, int);
	if (num < 0)
	{
		conv->neg = '-';
		conv->hassign = 1;
	}
	conv->numlen = ft_nbr_size(num);
	if (conv->left == 0 && conv->hash == 0 && conv->padzero == 0 &&
		conv->width == 0 && conv->precision == -2 && conv->blank == 0)
		ft_putnbr_c_fd(num, 1, conv, c_print);
	if ((conv->precision + conv->numlen) < conv->width)
		ft_trunc_width(num, 1, conv, c_print);
	if (conv->left == 0 && conv->hash == 0 && conv->padzero == 0 &&
		conv->width == 0 && conv->precision == -2 && conv->blank == 0
		&& conv->hassign == 1)
		ft_putnbr_c_fd(num, 1, conv, c_print);
}
	// 	// until width is finished. Remember the sign is counted
	// 	// in width
	// if ((conv->precision + numlen) < conv->width && conv->left == 1)
	// 	// print the number but the PADZERO flag is ignored.
	// if (conv->precision != -2 && conv->padzero == 1)
	// 	// ignore the PADZERO flag, just apply prec
	// if (conv->blank && conv->pos)
	// 	// ignore the blank



// void	ft_print_int(t_conv *conv, va_list a_list, int *c_print)
// {
// 	int	num;
// 	int	numlen;

// 	num = va_arg(a_list, int);
// 	if (num < 0)
// 	{
// 		conv->pos = '-';
// 		conv->hassign = 1;
// 	}
// 	numlen = ft_nbr_size(num);
// 	if (numlen < conv->precision || conv->precision == -2)
// 		conv->precision = numlen;
// 	if (conv->pos)
// 		ft_putchar_count_fd(conv->pos, 1, c_print);
// 	if (conv->left && num != 0)
// 		ft_putnbr_count_fd(num, 1, conv, c_print);
// 	if (conv->padzero && !conv->left)
// 		ft_padzero(conv->width, conv->precision, '0', c_print);
// 	else
// 		ft_padzero(conv->width, conv->precision, ' ', c_print);
// 	if (!conv->left && num != 0)
// 		ft_putnbr_count_fd(num, 1, conv, c_print);
// 	else if (conv->width == 0)
// 		ft_putnbr_count_fd(num, 1, conv, c_print);
// }

// void	ft_conv_unsign(t_conv *conv, va_list a_list, int *c_print)
// {

// }
