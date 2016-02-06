/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_unknown.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:48:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:31:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_unknown(t_argument *argument)
{
	ssize_t	total;

	total = 0;
	if (!argument->flags->minus && argument->width > 0 && argument->flags->zero)
		total += print_zeros(argument->width - 1);
	else if (!argument->flags->minus && argument->width > 0)
		total += print_spaces(argument->width - 1);
	ft_putchar(argument->type);
	total++;
	if (argument->flags->minus && argument->width > 0)
		total += print_spaces(argument->width - 1);
	return (total);
}
