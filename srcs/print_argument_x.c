/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:29:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:59:03 by acazuc           ###   ########.fr       */
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
	return (va_arg(*argument->va_lst, unsigned int));
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
	if (argument->flags->sharp && !(str = ft_strjoin_free2("0x", str)))
		return (-1);
	len = ft_strlen(str);
	if (!argument->flags->minus)
		total += print_argument_spaces(argument, len);
	if (argument->preci > 0 && (size_t)argument->preci > len)
		total += print_zeros(argument->preci - len);
	ft_putstr(str);
	free(str);
	total += len;
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len);
	return (total);
}
