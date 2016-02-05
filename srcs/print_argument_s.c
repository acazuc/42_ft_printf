/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 16:02:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_wstr(t_argument *argument)
{
	size_t	len;
	wchar_t	*str;
	char	cut;

	str = va_arg(*argument->va_lst, wchar_t*);
	if (!str)
		str = L"(null)";
	len = ft_wstrlen(str);
	cut = 0;
	if ((size_t)argument->preci < len)
	{
		cut = 1;
		if (!(str = ft_wstrsub(str, 0, argument->preci)))
			return ;
	}
	len = ft_wstrlen(str);
	if (!argument->flags->minus && argument->width > 0 && (size_t)argument->width > len)
		print_spaces(argument->width - len);
	ft_putwstr(str);
	if (argument->flags->minus && argument->width > 0 && (size_t)argument->width > len)
		print_spaces(argument->width - len);
	if (cut)
		free(str);
}

void	print_argument_s(t_argument *argument)
{
	size_t	len;
	char	*str;
	char	cut;

	if (argument->l)
		print_wstr(argument);
	str = va_arg(*argument->va_lst, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	cut = 0;
	if ((size_t)argument->preci < len)
	{
		cut = 1;
		if (!(str = ft_strsub(str, 0, argument->preci)))
			return ;
	}
	len = ft_strlen(str);
	if (!argument->flags->minus && argument->width > 0 && (size_t)argument->width > len)
		print_spaces(argument->width - len);
	ft_putstr(str);
	if (argument->flags->minus && argument->width > 0 && (size_t)argument->width > len)
		print_spaces(argument->width - len);
	if (cut)
		free(str);
}
