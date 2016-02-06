/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 15:42:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:52:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putwstr_fd(wchar_t *s, int fd)
{
	ssize_t	total;

	total = 0;
	while (*s)
	{
		total += ft_putwchar_fd(*s, fd);
		s++;
	}
	return (total);
}
