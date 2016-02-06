/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:35:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 14:59:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t		print_argument_2(t_argument *argument)
{
	if (argument->type == 'X')
		return (print_argument_x_caps(argument));
	else if (argument->type == 'c')
		return (print_argument_c(argument));
	else if (argument->type == 'C')
		return (print_argument_c_caps(argument));
	else
		return (print_argument_unknown(argument));
	return (0);
}

ssize_t				print_argument(t_argument *argument)
{
	if (argument->type == 's')
		return (print_argument_s(argument));
	else if (argument->type == 'S')
		return (print_argument_s_caps(argument));
	else if (argument->type == 'p')
		return (print_argument_p(argument));
	else if (argument->type == 'd')
		return (print_argument_d(argument));
	else if (argument->type == 'D')
		return (print_argument_d_caps(argument));
	else if (argument->type == 'i')
		return (print_argument_i(argument));
	else if (argument->type == 'o')
		return (print_argument_o(argument));
	else if (argument->type == 'O')
		return (print_argument_o_caps(argument));
	else if (argument->type == 'u')
		return (print_argument_u(argument));
	else if (argument->type == 'U')
		return (print_argument_u_caps(argument));
	else if (argument->type == 'x')
		return (print_argument_x(argument));
	else
		return (print_argument_2(argument));
}
