/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:26:40 by greed          #+#    #+#                */
/*   Updated: 2019/11/06 14:17:33 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(void *content)
{
	t_list		*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
