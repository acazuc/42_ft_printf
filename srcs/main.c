/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 11:55:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *str, ...)
{
	t_argument	*argument;
	va_list		list;
	size_t		i;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!(argument = parse_arg(str, &i, &list)))
				return ;
			print_argument(argument);
			argument_free(argument);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(list);
}

int		main(void)
{
	ft_printf("-%020.10u-\n", 160);
	   printf("-%020.10u-\n", 160);
	return (0);
}
