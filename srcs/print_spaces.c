/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 08:53:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:44:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_spaces(size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		ft_putchar(' ');
		count++;
	}
	return (len);
}
