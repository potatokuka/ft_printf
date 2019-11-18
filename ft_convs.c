/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 11:53:05 by greed          #+#    #+#                */
/*   Updated: 2019/11/18 14:27:49 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_conv_int(t_conv *conv, int *num)
{
	if (conv->size == 3)
		*num = ((short)*num);
	if (conv->size == 4)
		*num = ((char)*num);
	if (*num < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->numlen = ft_nbr_size(conv, *num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->numlen && conv->precision != 0))
		conv->precision = conv->numlen;
}
