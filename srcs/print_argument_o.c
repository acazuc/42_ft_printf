/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:26:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:59:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

ssize_t							print_argument_o(t_argument *argument)
{
	ssize_t					total;
	size_t					len;
	char					*str;
	unsigned long long int	val;

	val = get_val(argument);
	total = 0;
	if (!(str = ft_ultoa_base(val, "01234567")))
		return (-1);
	if (argument->flags->sharp && !(str = ft_strjoin_free2("0", str)))
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
