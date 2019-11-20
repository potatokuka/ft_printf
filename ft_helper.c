/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_helper.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:31:59 by greed          #+#    #+#                */
/*   Updated: 2019/11/19 13:51:19 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void		ft_pad_width(int width, int precision, int pad, int *lv)
{
	while (width > precision)
	{
		ft_putchar_c_fd(pad, 1, lv);
		width--;
	}
}

void		ft_putstr_c_fd(char *str, int fd, int n, int *lv)
{
	int		i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar_fd(str[i], fd);
		*lv += 1;
		i++;
	}
}

int			ft_valid_arg(const char **input, t_conv *conv)
{
	if (!*(*input + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}
