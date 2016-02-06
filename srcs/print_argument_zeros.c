/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_zeros.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:03:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 12:41:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_zeros(t_argument *arg, size_t len, int has_minux)
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
		if (has_minux)
			total--;
		print_zeros(total);
	}
	return (total);
}
