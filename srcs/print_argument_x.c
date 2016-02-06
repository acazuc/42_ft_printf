/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:29:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 16:31:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char						*get_chars(t_argument *argument)
{
	if (argument->type == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static unsigned long long int	get_val(t_argument *argument)
{
	if (argument->ll)
		return (va_arg(*argument->va_lst, unsigned long long int));
	else if (argument->l)
		return (va_arg(*argument->va_lst, unsigned long int));
	else if (argument->hh)
		return ((unsigned char)va_arg(*argument->va_lst, unsigned int));
	else if (argument->h)
		return ((unsigned short int)va_arg(*argument->va_lst, unsigned int));
	else if (argument->j)
		return ((uintmax_t)va_arg(*argument->va_lst, uintmax_t));
	else if (argument->z)
		return ((size_t)va_arg(*argument->va_lst, size_t));
	return (va_arg(*argument->va_lst, unsigned int));
}

static void						print_1(t_argument *argument
		, unsigned long long int val, size_t *len, ssize_t *total)
{
	if (argument->flags->sharp && (argument->type == 'p' || val))
		*len += 2;
	if (!argument->flags->minus && !argument->flags->zero)
		*total += print_argument_spaces(argument, *len, 0);
	else if (!argument->flags->minus)
		*total += print_argument_zeros(argument, *len, 0);
	if (argument->flags->sharp && (argument->type == 'p' || val))
	{
		*len -= 2;
		ft_putstr(argument->type == 'X' ? "0X" : "0x");
		*total += 2;
	}
}

ssize_t							print_argument_x(t_argument *argument)
{
	ssize_t					total;
	size_t					len;
	char					*str;
	unsigned long long int	val;

	total = 0;
	val = get_val(argument);
	if (!(str = ft_ultoa_base(val, get_chars(argument))))
		return (-1);
	len = ft_strlen(str);
	print_1(argument, val, &len, &total);
	if (argument->preci > 0 && (size_t)argument->preci > len)
		total += print_zeros(argument->preci - len);
	if (argument->preci)
	{
		ft_putstr(str);
		total += len;
	}
	free(str);
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len, 0);
	return (total);
}
