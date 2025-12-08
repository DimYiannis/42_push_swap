/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:14:29 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:29:09 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int				check_width_precision(t_print *tab, const char *c);
unsigned long	decide_conv(const char *c, t_print *tab);
int				check_flags(t_print *tab, const char *c);

unsigned int	eval_format(const char *c, t_print *tab)
{
	int	i;

	i = 0;
	i += check_flags(tab, &c[i]);
	if (ft_isdigit(c[i]) || c[i] == '.')
		i += check_width_precision(tab, &c[i]);
	if (ft_isalpha(c[i]) || c[i] == '%')
	{
		decide_conv(&c[i], tab);
		i++;
	}
	return (i);
}

unsigned long	decide_conv(const char *c, t_print *tab)
{
	unsigned long	i;

	i = 0;
	if (*c == 'd' || *c == 'i')
		i += int_case(tab);
	else if (*c == 'c')
		i += char_case(tab);
	else if (*c == 's')
		i += string_case(tab);
	else if (*c == 'x' || *c == 'X')
		i += hex_case(tab, c);
	else if (*c == 'p')
		i += pointer_case(tab);
	else if (*c == 'u')
		i += unsigned_case(tab);
	else if (*c == '%')
		i += percent_case(tab);
	return (i);
}

int	check_width_precision(t_print *tab, const char *c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (ft_isdigit(c[i]))
	{
		n = n * 10 + (c[i] - '0');
		i++;
	}
	tab->width = n;
	if (c[i] == '.')
	{
		i++;
		n = 0;
		while (ft_isdigit(c[i]))
		{
			n = n * 10 + (c[i] - '0');
			i++;
		}
		tab->precision = n;
	}
	return (i);
}

int	check_flags(t_print *tab, const char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '-')
			tab->dash = 1;
		else if (c[i] == ' ')
			tab->sp = 1;
		else if (c[i] == '+')
			tab->sign = 1;
		else if (c[i] == '#')
			tab->hash = 1;
		else if (c[i] == '0')
			tab->zero = 1;
		else
			break ;
		i++;
	}
	return (i);
}
