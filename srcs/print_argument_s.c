/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:46:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		test_free(char cut, void *str)
{
	if (cut)
		free(str);
}

static int		print_lol(t_argument *argument, size_t len)
{
	return (argument->width > 0
			&& (size_t)argument->width > len);
}

static void		leloul(t_argument *arg, ssize_t *total, size_t len, int m)
{
	int		minus;

	minus = arg->flags->minus;
	if (!m)
		minus = !minus;
	if (!m && minus && arg->flags->zero && print_lol(arg, len))
		*total += print_zeros(arg->width - len);
	else if (minus && print_lol(arg, len))
		*total += print_spaces(arg->width - len);
}

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
	leloul(argument, &total, len, 0);
	ft_putwstr(str);
	total += len;
	leloul(argument, &total, len, 1);
	test_free(cut, str);
	return (total);
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
	leloul(argument, &total, len, 0);
	ft_putstr(str);
	total += len;
	leloul(argument, &total, len, 1);
	test_free(cut, str);
	return (total);
}
