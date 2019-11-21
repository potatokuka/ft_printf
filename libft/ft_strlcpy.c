/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:34:26 by greed          #+#    #+#                */
/*   Updated: 2019/11/06 13:21:58 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	if (!(src))
		return (0);
	while (src[i] && i < (int)dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
