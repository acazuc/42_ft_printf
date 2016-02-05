/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:26:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 12:07:41 by acazuc           ###   ########.fr       */
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

void	print_argument_o(t_argument *argument)
{
	size_t					len;
	char					*str;
	unsigned long long int	val;

	val = get_val(argument);
	if (!(str = ft_ultoa_base(val, "01234567")))
		return ;
	if (argument->flags->sharp && !(str = ft_strjoin_free2("0", str)))
		return ;
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
