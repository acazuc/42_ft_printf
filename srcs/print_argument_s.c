/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 15:17:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	print_wstr(t_argument *argument)
{
	ssize_t	total;
	size_t	len;
	wchar_t	*str;
	char	cut;

	total = 0;
	str = va_arg(*argument->va_lst, wchar_t*);
	if (!str)
		str = L"(null)";
	len = ft_wstrlen(str);
	cut = 0;
	if ((size_t)argument->preci < len)
	{
		cut = 1;
		if (!(str = ft_wstrsub(str, 0, argument->preci)))
			return (-1);
	}
	len = ft_wstrlen(str);
	if (!argument->flags->minus && argument->width > 0
			&& (size_t)argument->width > len)
		total += print_spaces(argument->width - len);
	ft_putwstr(str);
	total += len;
	if (argument->flags->minus && argument->width > 0
			&& (size_t)argument->width > len)
		total += print_spaces(argument->width - len);
	if (cut)
		free(str);
	return (total);
}

static int		print_lol(t_argument *argument, size_t len)
{
	return (argument->width > 0
			&& (size_t)argument->width > len);
}

ssize_t			print_argument_s(t_argument *argument)
{
	ssize_t	total;
	size_t	len;
	char	*str;
	char	cut;

	total = 0;
	if (argument->l)
		return (print_wstr(argument));
	if (!(str = va_arg(*argument->va_lst, char*)))
		str = "(null)";
	cut = 0;
	if ((size_t)argument->preci < (len = ft_strlen(str)))
	{
		cut = 1;
		if (!(str = ft_strsub(str, 0, argument->preci)))
			return (-1);
	}
	len = ft_strlen(str);
	if (!argument->flags->minus && print_lol(argument, len))
		total += print_spaces(argument->width - len);
	ft_putstr(str);
	total += len;
	if (argument->flags->minus && print_lol(argument, len))
		total += print_spaces(argument->width - len);
	if (cut)
		free(str);
	return (total);
}
