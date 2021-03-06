/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:42:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/07 11:24:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_flags *flags, char *str, ssize_t *i)
{
	if (str[*i] == '-')
	{
		flags->zero = 0;
		flags->minus = 1;
	}
	else if (str[*i] == '+')
	{
		flags->space = 0;
		flags->plus = 1;
	}
	else if (str[*i] == '0' && !flags->minus)
		flags->zero = 1;
	else if (str[*i] == '#')
		flags->sharp = 1;
	else if (str[*i] == ' ' && !flags->plus)
		flags->space = 1;
	if (str[*i] == '-' || str[*i] == '+' || str[*i] == '0' || str[*i] == '#'
			|| str[*i] == ' ')
	{
		(*i)++;
		parse_flags(flags, str, i);
	}
}

static int	parse_preci(t_argument *argument, char *str, ssize_t *i)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (str[*i] != '.')
		return (1);
	(*i)++;
	start = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	end = *i;
	if (end == start)
	{
		argument->preci = 0;
		return (1);
	}
	if (!(result = ft_strsub(str, start, end - start)))
		return (0);
	argument->preci = ft_atoi(result);
	return (1);
}

t_argument	*parse_arg(char *str, ssize_t *i, va_list *lst)
{
	t_argument	*argument;

	if (!(argument = argument_create(lst)))
		return (NULL);
	parse_flags(argument->flags, str, i);
	if (!parse_width(argument, str, i))
	{
		argument_free(argument);
		return (NULL);
	}
	if (!parse_preci(argument, str, i))
	{
		argument_free(argument);
		return (NULL);
	}
	parse_length(argument, str, i);
	argument->type = str[*i];
	return (argument);
}
