/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:33:03 by greed          #+#    #+#                */
/*   Updated: 2019/11/14 16:07:34 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		ft_nbr_size(int i)
{
	int	tmp;
	int	size;

	tmp = i;
	size = 0;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp /= 10;
		size++;
	}
	return (size);
}

void		ft_putnbr_c_fd(int n, int fd, t_conv *conv, int *c_print)
{
	unsigned int		res;

	res = 0;
	if (conv->hassign == 1)
		ft_print_sign(fd, conv, c_print);
	if (n < 0)
		res = (unsigned int)(n * -1);
	else
		res = (unsigned int)n;
	if (res >= 10)
		ft_putnbr_c_fd(res / 10, fd, conv, c_print);
	ft_putchar_c_fd((char)(res % 10 + '0'), fd, c_print);
}

void		ft_trunc_width(int n, int fd, t_conv *conv, int *c_print)
{
	int				to_print;
	unsigned int	res;

	to_print = (conv->precision - conv->numlen);
	if (conv->hassign == 1)
		conv->width -= 1;
	while (conv->width > 0)
		ft_pad_width(conv->width, conv->precision, ' ', c_print);
	if (conv->hassign == 1)
		ft_print_sign(fd, conv, c_print);
	while (to_print >= 0)
	{
		res = 0;
		if (n < 0)
			res = (unsigned int)(n * -1);
		else
			res = (unsigned int)n;
		if (res >= 10)
			ft_putnbr_c_fd(res / 10, fd, conv, c_print);
		to_print -= 1;
		ft_putchar_c_fd((char)(res % 10 + '0'), fd, c_print);
	}
}

void		ft_print_sign(int fd, t_conv *conv, int *c_print)
{
	if (conv->pos == '+' && (conv->neg != '-'))
		ft_putchar_c_fd(conv->pos, fd, c_print);
	if (conv->neg == '-')
		ft_putchar_c_fd(conv->neg, fd, c_print);
	conv->hassign = 0;
}
