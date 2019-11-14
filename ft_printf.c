/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 10:15:46 by greed          #+#    #+#                */
/*   Updated: 2019/11/14 15:50:08 by greed         ########   odam.nl         */
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
	conv->blank = 0;
	conv->pos = 0;
	conv->len = 0;
	conv->hassign = 0;
	conv->neg = 0;
}

void			ft_converter_link(t_conv *conv, va_list a_list, int *c_print)
{
	char	*types;
	t_cfunc	funcs[13];
	int		i;

	types = "cspdiuxXnfge%";
	funcs[0] = &ft_print_char;
	funcs[1] = &ft_print_string;
	// funcs[2] = &ft_print_pointer;
	funcs[3] = &ft_conv_dec;
	funcs[4] = &ft_conv_dec;
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
	int		c_print;

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
