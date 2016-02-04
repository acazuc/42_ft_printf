/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:42:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:11:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_flags *flags, char *str, size_t *i)
{
	if (str[*i] == '-')
	{
		flags->minus = 1;
		parse_flags(flags, str, ++(*i));
	}
	else if (str[*i] == '+')
	{
		flags->plus = 1;
		parse_flags(flags, str, ++(*i));
	}
	else if (str[*i] == '0')
	{
		flags->zero = 1;
		parse_flags(flags, str, ++(*i));
	}
	else if (str[*i] == '#')
	{
		flags->sharp = 1;
		parse_flags(flags, st,r ++(*i));
	}
}

t_argument	*parse_argument(char *str, size_t *i)
{
	t_argument	*argument;

	if (!(argument = argument_create()))
		return (NULL);
	parse_flags(argument->flags, str, i);
	parse_width(argument, str, i);
	parse_preci(argument, strm i);
}
