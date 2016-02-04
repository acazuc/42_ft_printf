/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:34:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/04 18:41:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		parse_h(t_argument *argument, char *str, size_t *i)
{
	if (str[*i + 1] == 'h')
	{
		argument->hh = 1;
		(*i)++;
	}
	else
		argument->h = 1;
	(*i)++;
}

static void		parse_l(t_argument *argument, char *str, size_t *i)
{
	if (str[*i + 1] == 'l')
	{
		argument->ll = 1;
		(*i)++;
	}
	else
		argument->l = 1;
	(*i)++;
}

static void		parse_size(t_argument *argument, char *str, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	end = *i;
	if (end == start)
		return (1);
	if (!(result = ft_strsub(str, start, end - start)))
		return (0);
	argument->width = ft_atoi(result);
}

int	parse_width(t_argument *argument, char *str, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (str[*i] == 'h')
		parse_h(argument, str, i);
	else if (str[*i] == 'l')
		parse_l(argument, str, i);
	else if (str[*i] == 'j')
	{
		argument->j = 1;
		(*i)++;
	}
	else if (str[*i] == 'z')
	{
		argument->z = 1;
		(*i)++;
	}
	else
		parse_size(argument, str, i);
	return (1);
}
