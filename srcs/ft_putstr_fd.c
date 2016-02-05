/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:22:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 17:46:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	ssize_t		i;

	if (!s)
		i = write(fd, "(null)", 6);
	else
		i = write(fd, s, ft_strlen(s));
	(void)i;
}
