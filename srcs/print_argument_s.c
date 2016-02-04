/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 17:54:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_s(t_argument *argument)
{
	char	*str;

	str = va_arg(*argument->va_lst, char*);
	if (!str)
		ft_putstr("(null)");
	else
		ft_putstr(str);
}
