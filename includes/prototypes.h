/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:47:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/06 09:46:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "argument.h"
# include "flags.h"

int			ft_printf(char *str, ...);
t_argument	*parse_arg(char *str, size_t *i, va_list *lst);
int			parse_width(t_argument *argument, char *str, size_t *i);
void		parse_length(t_argument *argument, char *str, size_t *i);
ssize_t		print_spaces(size_t len);
ssize_t		print_zeros(size_t len);
ssize_t		print_argument_spaces(t_argument *arg, size_t len);
t_argument	*argument_create(va_list *lst);
void		argument_free(t_argument *argument);
t_flags		*flags_create(void);
ssize_t		print_argument(t_argument *argument);
ssize_t		print_argument_s(t_argument *argument);
ssize_t		print_argument_s_caps(t_argument *argument);
ssize_t		print_argument_p(t_argument *argument);
ssize_t		print_argument_d(t_argument *argument);
ssize_t		print_argument_d_caps(t_argument *argument);
ssize_t		print_argument_i(t_argument *argument);
ssize_t		print_argument_o(t_argument *argument);
ssize_t		print_argument_o_caps(t_argument *argument);
ssize_t		print_argument_u(t_argument *argument);
ssize_t		print_argument_u_caps(t_argument *argument);
ssize_t		print_argument_x(t_argument *argument);
ssize_t		print_argument_x_caps(t_argument *argument);
ssize_t		print_argument_c(t_argument *argument);
ssize_t		print_argument_c_caps(t_argument *argument);
ssize_t		print_argument_percent(t_argument *argument);
void		ft_putchar(char c);
void		ft_putwchar(wchar_t c);
void		ft_putchar_fd(char c, int fd);
void		ft_putwchar_fd(wchar_t c, int fd);
char		*ft_strsub(char const *str, unsigned int start, size_t len);
wchar_t		*ft_wstrsub(wchar_t const *str, unsigned int start, size_t len);
int			ft_atoi(const char *str);
void		ft_putstr(char const *str);
void		ft_putwstr(wchar_t const *str);
void		ft_putstr_fd(char const *str, int fd);
void		ft_putwstr_fd(wchar_t const *str, int fd);
size_t		ft_strlen(char const *str);
size_t		ft_wstrlen(wchar_t const *str);
char		*ft_ltoa(long long int val);
char		*ft_ultoa(unsigned long long int val);
char		*ft_ultoa_base(unsigned long long int val, char *base);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free2(char *s1, char *s2);
char		*ft_strdup(const char *s);

#endif
