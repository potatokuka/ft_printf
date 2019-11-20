/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sizes_xx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:41:55 by greed          #+#    #+#                */
/*   Updated: 2019/11/20 16:57:10 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void		ft_print_ll_x(t_conv *conv, va_list a_list, int *lv)
{
	unsigned long long		num;

	ft_negmod(conv, a_list, lv);
	num = va_arg(a_list, unsigned long long);
	ft_conv_ll_x(conv, &num);
	if (conv->hash && num != 0 && (conv->left || conv->padzero))
		ft_putstr_c_fd("0x", 1, 2, lv);
	if (conv->left)
	{
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_x_res_ll_c_fd(num, lv);
	}
	if (!conv->left && conv->padzero)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', lv);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', lv);
	if (!conv->left)
	{
		if (conv->hash && num != 0 && !conv->padzero)
			ft_putstr_c_fd("0x", 1, 2, lv);
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_x_res_ll_c_fd(num, lv);
	}
}

int		ft_x_ll_size(t_conv *conv, unsigned long long num)
{
	unsigned long long		tmp;
	int						size;

	size = 0;
	tmp = num;
	if (num == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void	ft_conv_ll_x(t_conv *conv, unsigned long long *num)
{
	if (conv->size == 3)
		*num = ((unsigned short)*num);
	if (conv->size == 4)
		*num = ((unsigned char)*num);
	conv->numlen = ft_x_ll_size(conv, *num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (num == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->numlen && conv->precision != 0))
		conv->precision = conv->numlen;
}

void		ft_x_res_ll_c_fd(unsigned long long num, int *lv)
{
	unsigned long long		res;
	unsigned long long		power;
	char					*hex;

	hex = "0123456789abcdef";
	res = num;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = num;
	while (power)
	{
		ft_putchar_c_fd(hex[num / power], 1, lv);
		num %= power;
		power /= 16;
	}
}

void		ft_upx_res_ll_c_fd(unsigned long long num, int *lv)
{
	unsigned long long		res;
	unsigned long long		power;
	char					*hex;

	hex = "0123456789ABCDEF";
	res = num;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = num;
	while (power)
	{
		ft_putchar_c_fd(hex[num / power], 1, lv);
		num %= power;
		power /= 16;
	}
}

void		ft_print_ll_up_x(t_conv *conv, va_list a_list, int *lv)
{
	unsigned long long		num;

	ft_negmod(conv, a_list, lv);
	num = va_arg(a_list, unsigned long long);
	ft_conv_ll_x(conv, &num);
	if (conv->hash && num != 0 && (conv->left || conv->padzero))
		ft_putstr_c_fd("0X", 1, 2, lv);
	if (conv->left)
	{
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_upx_res_ll_c_fd(num, lv);
	}
	if (!conv->left && conv->padzero)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', lv);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', lv);
	if (!conv->left)
	{
		if (conv->hash && num != 0 && !conv->padzero)
			ft_putstr_c_fd("0X", 1, 2, lv);
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_upx_res_ll_c_fd(num, lv);
	}
}
