/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d_caps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:47:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_d_caps(t_argument *argument)
{
	argument->l = 1;
	argument->ll = 0;
	argument->h = 0;
	argument->hh = 0;
	argument->j = 0;
	return (print_argument_d(argument));
}
