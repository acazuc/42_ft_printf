/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 16:34:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *str, ...)
{
	t_argument	*argument;
	va_list		arguments;
	size_t		i;

	va_start(arguments, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!(argument = parse_arg(str, &i)))
				return (NULL);
			print_argument(argument);
			free_argument(argument);
			if (str[i + 1] == 's')
			{
				ft_putstr(va_arg(arguments, char*));
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				ft_putnbr(va_arg(arguments, int));
				i++;
			}
			else if (str[i + 1] == 'c')
			{
				ft_putchar((char)va_arg(arguments, int));
				i++;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arguments);
}

int		main(void)
{
	ft_printf("-%s-%d-%c-%d-%s-\n", "mdr", 5, 'Q', 6, "lol");
	   printf("-%s-%d-%c-%d-%s-\n", "mdr", 5, 'Q', 6, "lol");
	return (0);
}
