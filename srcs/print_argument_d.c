/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:22:57 by acazuc           ###   ########.fr       */
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

static void				print_char(long long int val, t_argument *argument
		, ssize_t *total)
{
	if (val < 0)
	{
		ft_putchar('-');
		(*total)++;
	}
	else if (argument->flags->plus)
	{
		ft_putchar('+');
		(*total)++;
	}
	if (argument->flags->space && !argument->flags->plus && val >= 0)
	{
		ft_putchar(' ');
		(*total)++;
	}
}

static void				mdr(t_argument *argument, ssize_t *total, size_t *len
		, long long int *val)
{
	if (!argument->flags->minus && !argument->flags->zero)
		*total += print_argument_spaces(argument, *len, *val < 0
				|| argument->flags->plus || argument->flags->space);
	print_char(*val, argument, total);
	if (!argument->flags->minus && argument->flags->zero)
		*total += print_argument_zeros(argument, *len, *val < 0
				|| argument->flags->plus || argument->flags->space);
	if (argument->preci > 0 && (size_t)argument->preci > *len)
		*total += print_zeros(argument->preci - *len);
}

static void				norme(char *str, ssize_t *total, size_t len)
{
	ft_putstr(str);
	*total += len;
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
	len = ft_strlen(str);
	mdr(argument, &total, &len, &val);
	if (argument->preci)
		norme(str, &total, len);
	free(str);
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len, val < 0
				|| argument->flags->plus);
	return (total);
}
