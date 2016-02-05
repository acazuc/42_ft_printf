/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_c_caps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:32:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 11:11:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_c_caps(t_argument *argument)
{
	argument->ll = 0;
	argument->l = 1;
	argument->h = 0;
	argument->hh = 0;
	argument->z = 0;
	argument->j = 0;
	print_argument_c(argument);
}
