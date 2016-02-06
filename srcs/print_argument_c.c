/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:32:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:54:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_c(t_argument *argument)
{
	ssize_t	ret;
	ssize_t	total;
	wchar_t	val;

	total = 0;
	if (argument->l)
		val = (wchar_t)va_arg(*argument->va_lst, wint_t);
	else
		val = (unsigned char)va_arg(*argument->va_lst, int);
	if (argument->width > 0 && !argument->flags->minus
			&& !argument->flags->zero)
		total += print_spaces(argument->width - 1);
	else if (argument->width > 0 && !argument->flags->minus)
		total += print_zeros(argument->width - 1);
	if (argument->l)
	{
		if ((ret = ft_putwchar(val)) == -1)
			return (-1);
		total += ret;
	}
	else
	{
		ft_putchar(val);
		total++;
	}
	if (argument->width > 0 && argument->flags->minus)
		total += print_spaces(argument->width - 1);
	return (total);
}
