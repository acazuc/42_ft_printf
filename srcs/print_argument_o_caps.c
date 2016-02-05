/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_o_caps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:27:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 11:44:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument_o_caps(t_argument *argument)
{
	argument->ll = 0;
	argument->l = 1;
	argument->hh = 0;
	argument->h = 0;
	argument->j = 0;
	argument->z = 0;
	print_argument_o(argument);
}
