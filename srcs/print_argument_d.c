/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:47:23 by acazuc           ###   ########.fr       */
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

ssize_t					print_argument_d(t_argument *argument)
{
	ssize_t			total;
	size_t			len;
	char			*str;
	long long int	val;

	total = 0;
	val = get_val(argument);
	if (!(str = ft_ltoa(val)))
		return (-1);
	if (argument->flags->plus && val >= 0)
	{
		if (!(str = ft_strjoin_free2("+", str)))
			return (-1);
	}
	len = ft_strlen(str);
	if (!argument->flags->minus)
		total += print_argument_spaces(argument, len);
	if (argument->preci > 0 && (size_t)argument->preci > len)
		total += print_zeros(argument->preci - len);
	ft_putstr(str);
	total += len;
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len);
	return (total);
}
