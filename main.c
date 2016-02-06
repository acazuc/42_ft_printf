/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 16:54:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 17:50:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	setlocale(LC_CTYPE, "");
	int lol = ft_printf("%S\n", L"暖");
	int mdr =    printf("%S\n", L"暖");
	printf("ft_printf = %d\n   printf = %d\n", lol, mdr);
	return (0);
}
