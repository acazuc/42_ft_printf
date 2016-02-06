/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:26:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:37:28 by acazuc           ###   ########.fr       */
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
	else if (argument->j)
		return ((uintmax_t)va_arg(*argument->va_lst, uintmax_t));
	else if (argument->z)
		return ((size_t)va_arg(*argument->va_lst, size_t));
	return (va_arg(*argument->va_lst, unsigned int));
}

static void						mdr(t_argument *argument, ssize_t *total
		, size_t *len)
{
	if (argument->flags->sharp)
		(*len)++;
	if (!argument->flags->minus)
		(*total) += print_argument_spaces(argument, *len, 0);
	if (argument->flags->sharp)
	{
		(*len)--;
		ft_putchar('0');
		(*total)++;
	}
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
	len = ft_strlen(str);
	mdr(argument, &total, &len);
	if (argument->preci > 0 && (size_t)argument->preci > len)
		total += print_zeros(argument->preci - len
				- (argument->flags->sharp ? 1 : 0));
	if ((argument->preci && !val && !argument->flags->sharp) || val)
	{
		ft_putstr(str);
		total += len;
	}
	free(str);
	if (argument->flags->minus)
		total += print_argument_spaces(argument, len, 0);
	return (total);
}
