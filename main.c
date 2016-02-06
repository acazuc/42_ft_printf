/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 16:54:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 10:32:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int lol = ft_printf("%lU\n", 18446744073709551615u);
	int mdr =    printf("%lU\n", 18446744073709551615u);
	printf("ft_printf = %d - printf = %d\n", lol, mdr);
	return (0);
}
