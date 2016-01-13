/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:49:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 20:28:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *str, ...)
{
	va_list	arguments;
	int		i;

	va_start(arguments, *((int*)str));
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
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
	ft_printf("-%s-%d-%c-\n", "mdr", 5, 'Q');
	return (0);
}
