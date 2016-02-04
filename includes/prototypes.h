/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:47:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:23:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "argument.h"
# include "flags.h"

void	ft_printf(char *str, ...);
t_argument	*parse_argument(char *str, size_t *i);
t_argument	*argument_create(void);
void		argument_free(t_argument *argument);
t_flags		*flags_create(void);

#endif
