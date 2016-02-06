/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 15:31:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 14:27:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	unsigned char	str[4];
	int				width;

	width = 0;
    if (c < (1 << 7))
    {
        str[0] = (unsigned char)c;
		width =  1;
    }
    else if (c < (1 << 11))
    {
        str[0] = (unsigned char)((c >> 6) | 0xC0);
        str[1] = (unsigned char)((c & 0x3F) | 0x80);
		width = 2;
    }
    else if (c < (1 << 16))
	{
        str[0] = (unsigned char)(((c >> 12)) | 0xE0);
        str[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
        str[2] = (unsigned char)((c & 0x3F) | 0x80);
		width = 3;
    }
    else if (c < (1 << 21))
    {
        str[0] = (unsigned char)(((c >> 18)) | 0xF0);
        str[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
        str[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
        str[3] = (unsigned char)((c & 0x3F) | 0x80);
		width = 4;
	}
	write(fd, str, width);
}
