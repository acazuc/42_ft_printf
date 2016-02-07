/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:17:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/07 09:46:45 by acazuc           ###   ########.fr       */
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

static void		last_char(wchar_t *s1, wchar_t const *s2, size_t i, size_t len)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	if (i == len - 3)
	{
		ss1[i + 1] = ss2[i + 1];
		ss1[i + 2] = ss2[i + 2];
		ss1[i + 3] = '\0';
	}
	else if (i == len - 2)
	{
		ss1[i + 1] = ss2[i + 1];
		ss1[i + 2] = '\0';
		ss1[i + 3] = '\0';
	}
	else
	{
		ss1[i + 1] = '\0';
		ss1[i + 2] = '\0';
		ss1[i + 3] = '\0';
	}
	ss1[i + 0] = ss2[i + 0];
}

wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*ret;
	wchar_t	*result;
	size_t	i;

	if (!(result = malloc(sizeof(*result) * (len + 1))))
		return (result);
	ret = result;
	i = 0;
	s += start;
	while (i < len)
	{
		if (i + char_len(*s) >= len)
		{
			last_char(result, s, i, len);
			i = len;
		}
		else
		{
			i += char_len(*s);
			*result++ = *s++;
		}
	}
	*result = L'\0';
	return (ret);
}
