/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:21:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:54:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*flags_create(void)
{
	t_flags		*flags;

	if (!(flags = malloc(sizeof(*flags))))
		return (NULL);
	flags->minus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->sharp = 0;
	return (flags);
}
