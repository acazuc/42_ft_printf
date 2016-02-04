/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:44:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:59:02 by acazuc           ###   ########.fr       */
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
	return (argument);
}
