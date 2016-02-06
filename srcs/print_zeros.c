/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 09:27:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:45:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_zeros(size_t i)
{
	size_t	count;

	count = 0;
	while (count < i)
	{
		ft_putchar('0');
		count++;
	}
	return ((ssize_t)i);
}
