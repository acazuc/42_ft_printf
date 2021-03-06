/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:21:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:49:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_argument_p(t_argument *argument)
{
	argument->flags->sharp = 1;
	argument->l = 1;
	argument->ll = 0;
	argument->h = 0;
	argument->hh = 0;
	argument->z = 0;
	argument->j = 0;
	return (print_argument_x(argument));
}
