/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 16:54:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 16:55:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int lol = ft_printf("%-15p\n", 0);
	int mdr =    printf("%-15p\n", 0);
	printf("ft_printf = %d\n   printf = %d\n", lol, mdr);
	return (0);
}
