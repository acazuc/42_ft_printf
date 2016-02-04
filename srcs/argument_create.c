/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:44:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 18:55:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_argument	*argument_create(va_list *lst)
{
	t_argument	*argument;
	t_flags		*flags;

	if (!(flags = flags_create()))
		return (NULL);
	if (!(argument = malloc(sizeof(*argument))))
	{
		free(flags);
		return (NULL);
	}
	argument->va_lst = lst;
	argument->flags = flags;
	argument->width = -1;
	argument->preci = -1;
	argument->type = '\0';
	argument->l = 0;
	argument->ll = 0;
	argument->h = 0;
	argument->hh = 0;
	argument->j = 0;
	argument->z = 0;
	return (argument);
}
