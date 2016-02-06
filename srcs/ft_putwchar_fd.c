/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 15:31:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 14:59:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_1(char **str, int *width, wchar_t c)
{
	(*str)[0] = (unsigned char)c;
	*width = 1;
}

static void	case_2(char **str, int *width, wchar_t c)
{
	(*str)[0] = (unsigned char)((c >> 6) | 0xC0);
	(*str)[1] = (unsigned char)((c & 0x3F) | 0x80);
	*width = 2;
}

static void	case_3(char **str, int *width, wchar_t c)
{
	(*str)[0] = (unsigned char)(((c >> 12)) | 0xE0);
	(*str)[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
	(*str)[2] = (unsigned char)((c & 0x3F) | 0x80);
	*width = 3;
}

static void	case_4(char **str, int *width, wchar_t c)
{
	(*str)[0] = (unsigned char)(((c >> 18)) | 0xF0);
	(*str)[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
	(*str)[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
	(*str)[3] = (unsigned char)((c & 0x3F) | 0x80);
	*width = 4;
}

void		ft_putwchar_fd(wchar_t c, int fd)
{
	char	str[4];
	char	*mdr;
	int		width;

	width = 0;
	mdr = &(str[0]);
	if (c < (1 << 7))
		case_1(&mdr, &width, c);
	else if (c < (1 << 11))
		case_2(&mdr, &width, c);
	else if (c < (1 << 16))
		case_3(&mdr, &width, c);
	else if (c < (1 << 21))
		case_4(&mdr, &width, c);
	write(fd, mdr, width);
}
