/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 15:55:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:57:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	char_len(wchar_t c)
{
	if (c < (1 << 7))
		return (1);
	if (c < (1 << 11))
		return (2);
	if (c < (1 << 16))
		return (3);
	if (c < (1 << 21))
		return (4);
	return (0);
}

size_t			ft_wstrlen(wchar_t const *s)
{
	size_t	total;

	total = 0;
	while (*s)
	{
		total += char_len(*s);
		s++;
	}
	return (total);
}
