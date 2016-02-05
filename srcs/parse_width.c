/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:34:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 08:44:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_width(t_argument *argument, char *str, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	end = *i;
	if (end == start)
		return (1);
	if (!(result = ft_strsub(str, start, end - start)))
		return (0);
	argument->width = ft_atoi(result);
	return (1);
}
