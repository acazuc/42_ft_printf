/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:20:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:46:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static size_t	get_size(unsigned long long int n, char *base)
{
	size_t					size;
	size_t					base_len;

	size = 1;
	base_len = ft_strlen(base);
	while (n > 0)
	{
		size++;
		n /= base_len;
	}
	return (size);
}

char			*ft_ultoa_base(unsigned long long int n, char *base)
{
	char					*result;
	size_t					size;
	size_t					base_len;
	unsigned long long int	j;
	unsigned long long int	i;

	if (!base | ((base_len = ft_strlen(base)) < 2))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n, base);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	j = 1;
	i = 1;
	while (n / j > 0 && j != ULONG_MAX)
	{
		result[size - i++ - 1] = base[(n / j) % base_len];
		j = j >= ULONG_MAX / base_len ? ULONG_MAX : j * ft_strlen(base);
	}
	result[size - 1] = '\0';
	return (result);
}
