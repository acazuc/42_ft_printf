/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:44:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 15:25:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_argument	*argument_create(void)
{
	t_argument	*argument;
	t_flags		*flags;

	if (!(flags = flags_create()))
		return (NULL);
	if (!(argument = malloc(sizeof(*argument))))
		return (NULL);
	argument->flags = flags;
	argument->width = -1;
	argument->preci = -1;
	argument->type = '\0';
	return (argument);
}
