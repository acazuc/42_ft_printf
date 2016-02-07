/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:17:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/07 09:24:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	char_len(wchar_t c)
{
	if (c < (1 << 7))
		return (1);
	if (c < (1 << 1))
		return (2);
	if (c < (1 << 16))
		return (3);
	if (c < (1 << 21))
		return (4);
	return (0);
}

wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*ret;
	wchar_t	*result;
	size_t	i;

	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (result);
	ret = result;
	i = 0;
	s += start;
	while (i < len)
	{
		*result = *s;
		i += char_len(*s);
		s++;
		result++;
	}
	*result = L'\0';
	return (ret);
}
