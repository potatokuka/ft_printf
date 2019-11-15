/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flag_func.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 17:13:38 by greed          #+#    #+#                */
/*   Updated: 2019/11/15 15:22:17 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void			ft_find_type(const char **input, t_conv *conv)
{
	char	*types;

	*input += 1;
	while (**input)
	{
		types = "cspdiuxXnfeg%";
		while (*types)
		{
			if (**input == *types)
			{
				conv->type = *types;
				return ;
			}
			types++;
		}
		ft_flag_check(input, conv);
		*input += 1;
	}
}

void			ft_precision_check(const char **input, t_conv *conv)
{
	if (*(*input + 1) == '*')
		conv->precision = -1;
	else if (ft_isdigit(*(*input + 1)))
		conv->precision = ft_atoi(*input + 1);
	else
	{
		conv->precision = 0;
		*input -= 1;
	}
	*input += 1;
}

void			ft_flag_check(const char **input, t_conv *conv)
{
	if (**input == '#')
		conv->hash = 1;
	else if (**input == '-')
		conv->left = 1;
	else if (**input == '0')
		conv->padzero = 1;
	else if (**input == ' ' || **input == '+')
	{
		conv->sign = **input;
		conv->hassign = 1;
	}
	else if (**input == '*')
		conv->width = -1;
	else if (ft_isdigit(**input))
		conv->width = ft_atoi(*input);
	else if (**input == '.')
		ft_precision_check(input, conv);
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*input)) && ft_isdigit(*(*input + 1)))
			*input += 1;
}

// check for input[i] against legnth array "llhh"
// if input [i+1] == 'l' && input == length[0]
// if input [i+1] == 'h' && input == length[3]
// run through the input string fully with [i]
// first to make sure you dont move the string
// and fuck up other checks.
