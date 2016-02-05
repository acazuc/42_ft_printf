/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 11:28:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	get_val(t_argument *argument)
{
	if (argument->ll)
		return (va_arg(*argument->va_lst, long long int));
	else if (argument->l)
		return (va_arg(*argument->va_lst, long int));
	else if (argument->hh)
		return ((signed char)va_arg(*argument->va_lst, int));
	else if (argument->h)
		return ((short int)va_arg(*argument->va_lst, int));
	return (va_arg(*argument->va_lst, int));
}

void	print_argument_d(t_argument *argument)
{
	size_t			len;
	char			*str;
	long long int	val;

	val = get_val(argument);
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
