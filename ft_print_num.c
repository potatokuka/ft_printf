/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:33:03 by greed          #+#    #+#                */
/*   Updated: 2019/11/18 14:27:37 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int			ft_nbr_size(t_conv *conv, int num)
{
	int		tmp;
	int		size;

	tmp = num;
	size = 0;
	if (num == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

void		ft_intres_c_fd(int num, int *lv)
{
	int		res;
	int		power;

	res = num;
	power = 1;
	while (res / 10)
	{
		res /= 10;
		power *= 10;
	}
	while (power)
	{
		if (num < 0)
			ft_putchar_c_fd(('0' - num / power), 1, lv);
		if (!(num < 0))
			ft_putchar_c_fd(('0' + num / power), 1, lv);
		num %= power;
		power /= 10;
	}
}

void		ft_print_int(t_conv *conv, va_list a_list, int *lv)
{
	int		num;

	if (conv->size == 1 || conv->size == 2)
		return (ft_size_num(conv, a_list, lv));
	num = va_arg(a_list, int);
	ft_conv_int(conv, &num);
	if (conv->hassign && (conv->padzero || conv->left))
		ft_putchar_c_fd(conv->sign, 1, lv);
	if (conv->left)
	{
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_intres_c_fd(num, lv);
	}
	if (!conv->left && conv->padzero)
		ft_pad_width(conv->width, conv->precision + conv->hassign, '0', lv);
	else
		ft_pad_width(conv->width, conv->precision + conv->hassign, ' ', lv);
	if (!conv->left)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_c_fd(conv->sign, 1, lv);
		ft_pad_width(conv->precision, conv->numlen, '0', lv);
		if (conv->precision)
			ft_intres_c_fd(num, lv);
	}
}
