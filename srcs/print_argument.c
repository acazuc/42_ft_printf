/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:35:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:48:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_argument_2(t_argument *argument)
{
	if (argument->type == 'X')
		print_argument_x_caps(argument);
	else if (argument->type == 'c')
		print_argument_c(argument);
	else if (argument->type == 'C')
		print_argument_c_caps(argument);
}

void			print_argument(t_argument *argument)
{
	if (argument->type == 's')
		print_argument_s(argument);
	else if (argument->type == 'S')
		print_argument_s_caps(argument);
	else if (argument->type == 'p')
		print_argument_p(argument);
	else if (argument->type == 'd')
		print_argument_d(argument);
	else if (argument->type == 'D')
		print_argument_d_caps(argument);
	else if (argument->type == 'i')
		print_argument_i(argument);
	else if (argument->type == 'o')
		print_argument_o(argument);
	else if (argument->type == 'O')
		print_argument_o_caps(argument);
	else if (argument->type == 'u')
		print_argument_u(argument);
	else if (argument->type == 'U')
		print_argument_u_caps(argument);
	else if (argument->type == 'x')
		print_argument_x(argument);
	else
		print_argument_2(argument);
}
