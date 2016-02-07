/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/07 11:24:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		nothing(ssize_t *total, char c)
{
	(*total)++;
	ft_putchar(c);
}

static int		c_q(va_list *l, int a)
{
	if (a)
	{
		va_end(*l);
		return (1);
	}
	return (0);
}

static void		init(ssize_t *i, ssize_t *total)
{
	*i = -1;
	*total = 0;
}

int				ft_printf(char *str, ...)
{
	t_argument	*argument;
	ssize_t		total;
	ssize_t		ret;
	va_list		list;
	ssize_t		i;

	va_start(list, str);
	init(&i, &total);
	while (str[++i])
		if (str[i] == '%')
		{
			if (c_q(&list, !str[i + 1]))
				return (total);
			i++;
			if (c_q(&list, !(argument = parse_arg(str, &i, &list)))
					|| c_q(&list, (ret = print_argument(argument)) == -1))
				return (-1);
			total += ret;
			argument_free(argument);
		}
		else
			nothing(&total, str[i]);
	va_end(list);
	return (total);
}
