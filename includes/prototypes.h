/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:47:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 13:10:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "argument.h"
# include "flags.h"

void		ft_printf(char *str, ...);
t_argument	*parse_arg(char *str, size_t *i, va_list *lst);
int			parse_width(t_argument *argument, char *str, size_t *i);
void		parse_length(t_argument *argument, char *str, size_t *i);
void		print_spaces(size_t len);
void		print_zeros(size_t len);
void		print_argument_spaces(t_argument *arg, size_t len);
t_argument	*argument_create(va_list *lst);
void		argument_free(t_argument *argument);
t_flags		*flags_create(void);
void		print_argument(t_argument *argument);
void		print_argument_s(t_argument *argument);
void		print_argument_s_caps(t_argument *argument);
void		print_argument_p(t_argument *argument);
void		print_argument_d(t_argument *argument);
void		print_argument_d_caps(t_argument *argument);
void		print_argument_i(t_argument *argument);
void		print_argument_o(t_argument *argument);
void		print_argument_o_caps(t_argument *argument);
void		print_argument_u(t_argument *argument);
void		print_argument_u_caps(t_argument *argument);
void		print_argument_x(t_argument *argument);
void		print_argument_x_caps(t_argument *argument);
void		print_argument_c(t_argument *argument);
void		print_argument_c_caps(t_argument *argument);
void		print_argument_percent(t_argument *argument);

#endif
