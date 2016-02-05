/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 09:35:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_d(t_argument *argument)
{
	size_t	len;
	char	*str;
	int		val;

	if (argument->l)
		print_argument_s_caps(argument);
	val = va_arg(*argument->va_lst, int);
	if (!(str = ft_itoa(val)))
		return ;
	if (argument->flags->plus && val >= 0)
	{
		if (!(str = ft_strjoin_free2("+", str)))
			return ;
	}
	len = ft_strlen(str);
	if (!argument->flags->minus && argument->width > 0
			&& ((argument->preci <= 0 && (size_t)argument->width > len)
				|| (argument->preci >= 1 && (size_t)argument->width > MAX((size_t)argument->preci, len))))
		print_spaces(argument->width - (argument->preci <= 0 ? len : MAX((size_t)argument->preci, len)));
	if (argument->preci > 0 && (size_t)argument->preci > len)
		print_zeros(argument->preci - len);
	ft_putstr(str);
	if (argument->flags->minus && argument->width > 0
			&& ((argument->preci <= 0 && (size_t)argument->width > len)
				|| (argument->preci >= 1 && (size_t)argument->width > MAX((size_t)argument->preci, len))))
		print_spaces(argument->width - (argument->preci <= 0 ? len : MAX((size_t)argument->preci, len)));
}
