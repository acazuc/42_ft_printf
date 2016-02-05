/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:32:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 11:07:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_c(t_argument *argument)
{
	wint_t	val;

	if (argument->l)
		val = va_arg(*argument->va_lst, wint_t);
	else
		val = (char)va_arg(*argument->va_lst, int);
	if (argument->width > 0 && !argument->flags->minus)
		print_spaces(argument->width - 1);
	ft_putchar(val);
	if (argument->width > 0 && argument->flags->minus)
		print_spaces(argument->width - 1);
}
