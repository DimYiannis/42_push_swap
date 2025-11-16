/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_helpers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:09:18 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:30:01 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_neg(long long *num)
{
	int	neg;

	neg = 0;
	if (*num < 0)
	{
		*num = -*num;
		neg = 1;
	}
	return (neg);
}

int	get_padding(t_print *tab, int len, int neg)
{
	int	padding;

	padding = tab->width - (len + tab->is_zero);
	if (neg || tab->sign || tab->sp)
		padding--;
	if (padding < 0)
		padding = 0;
	return (padding);
}

int	print_num_space(t_print *tab, char *tmp, int len, int padding)
{
	int	written;

	written = 0;
	written += putchar_n('0', tab->is_zero);
	written += putstring_n(tmp, len);
	if (tab->dash)
		written += putchar_n(' ', padding);
	return (written);
}
