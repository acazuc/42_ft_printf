/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:32:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:53:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_c(t_argument *argument)
{
	ssize_t	total;
	wint_t	val;

	total = 0;
	if (argument->l)
		val = va_arg(*argument->va_lst, wint_t);
	else
		val = (unsigned char)va_arg(*argument->va_lst, int);
	if (argument->width > 0 && !argument->flags->minus)
		total += print_spaces(argument->width - 1);
	if (argument->l)
		ft_putwchar(val);
	else
		ft_putchar(val);
	total++;
	if (argument->width > 0 && argument->flags->minus)
		total += print_spaces(argument->width - 1);
	return (total);
}
