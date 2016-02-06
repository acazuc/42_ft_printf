/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:03:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:46:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_spaces(t_argument *arg, size_t len)
{
	ssize_t	total;
	size_t	preci;
	size_t	width;

	preci = (size_t)arg->preci;
	width = (size_t)arg->width;
	total = 0;
	if (arg->width > 0 && ((arg->preci <= 0 && width > len)
				|| (arg->preci >= 1 && width > MAX(preci, len))))
	{
		total = arg->width - (arg->preci <= 0 ? len : MAX(preci, len));
		print_spaces(total);
	}
	return (total);
}
