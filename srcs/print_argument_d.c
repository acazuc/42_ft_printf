/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 11:37:27 by acazuc           ###   ########.fr       */
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
	else if (argument->j)
		return ((intmax_t)va_arg(*argument->va_lst, intmax_t));
	else if (argument->z)
		return ((ssize_t)va_arg(*argument->va_lst, ssize_t));
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
	if (val < 0 && !(str = ft_strsub(str, 1, ft_strlen(str) - 1)))
	{
		free(str);
		return (-1);
	}
	if (argument->flags->plus && val >= 0)
	{
		if (!(str = ft_strjoin_free2("+", str)))
			return (-1);
	}
	len = ft_strlen(str);
	if (!argument->flags->minus)
		total += print_argument_spaces(argument, len, val < 0);
	if (val < 0)
	{
		ft_putchar('-');
		total++;
	}
	if (argument->preci > 0 && (size_t)argument->preci > len)
		total += print_zeros(argument->preci - len);
	if (argument->flags->space && !argument->flags->plus && val > 0)
	{
		ft_putchar(' ');
		total++;
	}
	ft_putstr(str);
	free(str);
	total += len;
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len, val < 0);
	return (total);
}
