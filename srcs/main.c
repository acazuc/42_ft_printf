/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 16:17:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		percent(size_t *i, ssize_t *total)
{
	(*i)++;
	ft_putchar('%');
	(*total)++;
}

static void		nothing(ssize_t *total, char c)
{
	(*total)++;
	ft_putchar(c);
}

static int		check_quit(va_list *l, int a)
{
	if (a)
	{
		va_end(*l);
		return (1);
	}
	return (0);
}

int				ft_printf(char *str, ...)
{
	t_argument	*argument;
	ssize_t		total;
	ssize_t		ret;
	va_list		list;
	size_t		i;

	va_start(list, str);
	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (check_quit(&list, !str[i + 1]))
				return (total);
			if (str[i + 1] == '%')
				percent(&i, &total);
			else
			{
				i++;
				if (check_quit(&list, !(argument = parse_arg(str, &i, &list)))
						|| check_quit(&list
							, (ret = print_argument(argument)) == -1))
					return (-1);
				total += ret;
				argument_free(argument);
			}
		}
		else
			nothing(&total, str[i]);
		i++;
	}
	va_end(list);
	return (total);
}
