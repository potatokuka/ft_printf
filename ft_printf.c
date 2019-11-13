/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 10:15:46 by greed          #+#    #+#                */
/*   Updated: 2019/11/13 11:36:38 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void			ft_flag_vars_set(t_conv *conv)
{
	conv->left = 0;
	conv->hash = 0;
	conv->padzero = 0;
	conv->width = 0;
	conv->precision = -2;
	conv->sign = 0;
}

void			ft_find_type(const char **input, t_conv *conv)
{
	char	*types;

	*input += 1;;
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


void			ft_flag_check(const char **input, t_conv *conv)
{
	if (**input == '-')
		conv->left = 1;
	else if (**input == '0')
		conv->padzero = 1;
	else if (**input == '+' || **input == ' ')
		conv->sign = **input;
	else if (**input == '*')
		conv->width = -1;
	else if (ft_isdigit(**input))
		conv->width = ft_atoi(*input);
	else if (**input == '.')
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
	if (conv->precision != -2 || conv->width != 0)
			while (ft_isdigit(*(*input)) && ft_isdigit(*(*input + 1)))
					*input += 1;
}

void			ft_converter_link(t_conv *conv, va_list a_list, int *c_print)
{
	char	*types;
	t_cfunc	funcs[13];
	int				i;

	types = "cspdiuxXnfge%";
	funcs[0] = &ft_print_char;
	funcs[1] = &ft_print_string;
	// funcs[2] = &ft_print_pointer;
	// funcs[3] = &ft_print_int;
	// funcs[4] = &ft_print_int;
	// funcs[5] = &ft_print_uint;
	// funcs[6] = &ft_print_hex_lower;
	// funcs[7] = &ft_print_hex_upper;
	// funcs[8] = &ft_print_count;
	// funcs[9] = &ft_print_float;
	// funcs[10] = &ft_print_science;
	// funcs[11] = &ft_print_comp_float;
	// funcs[12] = &ft_print_percent;
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
				funcs[i](conv, a_list, c_print);
		i++;
	}
}

	


/* 
** c_print is counter for how many things are to be printed
*/

int				ft_printf(const char *input, ...)
{
	va_list a_list;
	t_conv	conv;
	int				c_print;

	va_start(a_list, input);
	c_print = 0;
	while (*input)
	{
		if (*input != '%')
		{
			ft_putchar_fd(*input, 1);
			c_print++;
		}
		else
		{
			ft_flag_vars_set(&conv);
			ft_find_type(&input, &conv);
			if (conv.width == -1)
					conv.width = va_arg(a_list, int);
			if (conv.precision == -1)
					conv.precision = va_arg(a_list, int);
			ft_converter_link(&conv, a_list, &c_print);
		}
		input++;
	}
	va_end(a_list);
	return (c_print);
}
