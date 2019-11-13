/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_helper.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:31:59 by greed          #+#    #+#                */
/*   Updated: 2019/11/13 11:10:49 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void		ft_pad_width(int width, int precision, int pad, int *c_print)
{
	while (width > precision)
	{
		*c_print += 1;
		ft_putchar_fd(pad, 1);
		width--;
	}
}

void		ft_putstr_c_fd(char *str, int fd, int n, int *c_print)
{
	int		i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar_fd(str[i], fd);
		*c_print += 1;
		i++;
	}
}

// void		ft_putchar_c_fd(char c, int fd, int *c_print)
// {
// 	ft_putchar_fd(c, fd);
// 	*c_print += 1;
// }