/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:35:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 15:21:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H

# include "flags.h"

typedef struct	s_argument
{
	t_flags		*flags;
	int			width;
	int			preci;
	char		type;
}				t_argument;

#endif
