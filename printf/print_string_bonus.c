/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 10:47:21 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	compute_string(char **s, t_print *tab)
{
	int	len;

	*s = va_arg(tab->args, char *);
	if (!*s)
	{
		if (tab->precision == 0)
			*s = "";
		else if (tab->precision >= 0 && tab->precision < 6)
			*s = "";
		else
			*s = "(null)";
	}
	len = ft_strlen(*s);
	if (tab->precision >= 0 && tab->precision < len)
		len = tab->precision;
	return (len);
}

int	string_case(t_print *tab)
{
	int		len;
	int		padding;
	char	*s;

	len = compute_string(&s, tab);
	padding = 0;
	if (tab->width > len)
		padding = tab->width - len;
	if (!tab->dash && padding > 0)
		tab->total_length += putchar_n(' ', padding);
	tab->total_length += putstring_n(s, len);
	if (tab->dash && padding > 0)
		tab->total_length += putchar_n(' ', padding);
	return (tab->total_length);
}
