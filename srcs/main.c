/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:08:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
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
			if (!str[i + 1])
				return (total);
			if (str[i + 1] == '%')
			{
				i++;
				ft_putchar('%');
				total++;
			}
			else
			{
				i++;
				if (!(argument = parse_arg(str, &i, &list)))
					return (-1);
				if ((ret = print_argument(argument)) == -1)
					return (-1);
				else
					total += ret;
				argument_free(argument);
			}
		}
		else
		{
			total++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(list);
	return (total);
}
