/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:29:50 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			dash;
	int			total_length;
	int			sign;
	int			sp;
	int			hash;
	int			is_zero;
}				t_print;

typedef struct s_hexinfo
{
	int			len;
	int			zeros;
	int			padding;
	int			prefix;
	int			upper;
}				t_hexinfo;

int				char_case(t_print *tab);
int				string_case(t_print *tab);
int				pointer_case(t_print *tab);
int				hex_case(t_print *tab, const char *c);
int				int_case(t_print *tab);
int				unsigned_case(t_print *tab);
int				percent_case(t_print *tab);
int				ft_printf(const char *type, ...);
unsigned int	eval_format(const char *c, t_print *tab);
unsigned int	putchar_n(char c, unsigned int n);
unsigned int	putstring_n(char *s, unsigned int n);
char			*ft_unsigneditoa(unsigned int n);
int				count_decimal_digits(unsigned int n);
int				print_hex_right(t_print *tab, char *tmp, unsigned int num,
					t_hexinfo info);
int				print_hex_left(char *tmp, unsigned int num, t_hexinfo info);
int				handle_neg(long long *num);
int				get_padding(t_print *tab, int len, int neg);
int				print_num_space(t_print *tab, char *tmp, int len, int padding);

#endif