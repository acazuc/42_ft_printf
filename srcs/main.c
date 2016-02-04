/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 17:56:06 by acazuc           ###   ########.fr       */
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
			/*if (str[i + 1] == 's')
			{
				ft_putstr(va_arg(list, char*));
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				ft_putnbr(va_arg(list, int));
				i++;
			}
			else if (str[i + 1] == 'c')
			{
				ft_putchar((char)va_arg(list, int));
				i++;
			}*/
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(list);
}

int		main(void)
{
	ft_printf("-%s-%d-%c-%d-%s-\n", "mdr", 5, 'Q', 6, "lol");
	   printf("-%s-%d-%c-%d-%s-\n", "mdr", 5, 'Q', 6, "lol");
	return (0);
}
