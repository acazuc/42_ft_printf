/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 09:43:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:55:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static size_t	get_size(long long int n)
{
	size_t					size;

	size = n < 0 ? 2 : 1;
	if (n == LLONG_MIN)
	{
		n = 0 - n / 10;
		size++;
	}
	else
		n = n < 0 ? -n : n;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_ltoa(long long int n)
{
	char					*result;
	size_t					size;
	unsigned long long int	j;
	unsigned long long int	i;
	unsigned long long int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n < 0 ? -n : n;
	size = get_size(n);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	if (n < 0)
		result[0] = '-';
	j = 1;
	i = 1;
	while (nb / j > 0 && j != LLONG_MAX)
	{
		result[size - i++ - 1] = (nb / j) % 10 + '0';
		j = j >= LLONG_MAX / 10 ? LLONG_MAX : j * 10;
	}
	result[size - 1] = '\0';
	return (result);
}
