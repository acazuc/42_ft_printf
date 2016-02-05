/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_d_caps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 10:02:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_d_caps(t_argument *argument)
{
	argument->l = 1;
	argument->ll = 0;
	argument->h = 0;
	argument->hh = 0;
	argument->j = 0;
	print_argument_d(argument);
}
