/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 16:54:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:40:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int lol = ft_printf("%lx\n", ULONG_MAX);
	int mdr =    printf("%lx\n", ULONG_MAX);
	printf("ft_printf = %d - printf = %d\n", lol, mdr);
	return (0);
}
