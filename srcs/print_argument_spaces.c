/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:03:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 13:10:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_spaces(t_argument *arg, size_t len)
{
	size_t	preci;
	size_t	width;

	preci = (size_t)arg->preci;
	width = (size_t)arg->width;
	if (arg->width > 0 && ((arg->preci <= 0 && width > MAX(preci, len))))
		print_spaces(arg->width - (arg->preci <= 0 ? len : MAX(preci, len)));
}
