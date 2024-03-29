/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:29:25 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 13:55:41 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int		res;

	res = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = (unsigned int)(n * -1);
	}
	else
		res = (unsigned int)n;
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd((char)(res % 10 + '0'), fd);
}
