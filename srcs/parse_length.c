/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 08:38:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 08:45:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_h(t_argument *argument, char *str, size_t *i)
{
	if (str[*i + 1] == 'h')
	{
		argument->hh = 1;
		(*i)++;
	}
	else
		argument->h = 1;
	(*i)++;
}

static void	parse_l(t_argument *argument, char *str, size_t *i)
{
	if (str[*i + 1] == 'l')
	{
		argument->ll = 1;
		(*i)++;
	}
	else
		argument->l = 1;
	(*i)++;
}

void		parse_length(t_argument *argument, char *str, size_t *i)
{
	if (str[*i] == 'h')
		parse_h(argument, str, i);
	else if (str[*i] == 'l')
		parse_l(argument, str, i);
	else if (str[*i] == 'j')
	{
		argument->j = 1;
		(*i)++;
	}
	else if (str[*i] == 'z')
	{
		argument->z = 1;
		(*i)++;
	}
}
