/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:30:07 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	char_case(t_print *tab)
{
	int		padding;
	char	c;

	padding = 0;
	c = (char)va_arg(tab->args, int);
	if (tab->width > 1)
		padding = tab->width - 1;
	if (!tab->dash)
		tab->total_length += putchar_n(' ', padding);
	tab->total_length += write(1, &c, 1);
	if (tab->dash)
		tab->total_length += putchar_n(' ', padding);
	return (tab->total_length);
}
