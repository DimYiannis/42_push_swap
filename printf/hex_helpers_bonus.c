/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:58:58 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/30 12:42:41 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_prefix(unsigned int num, int upper, int hash)
{
	if (!hash || num == 0)
		return (0);
	if (upper)
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

static int	print_main(char *tmp, int len, int zeros)
{
	int	written;

	written = 0;
	written += putchar_n('0', zeros);
	written += putstring_n(tmp, len);
	return (written);
}

int	print_hex_left(char *tmp, unsigned int num, t_hexinfo info)
{
	int	written;

	written = 0;
	written += print_prefix(num, info.upper, info.prefix);
	written += print_main(tmp, info.len, info.zeros);
	written += putchar_n(' ', info.padding);
	return (written);
}

int	print_hex_right(t_print *tab, char *tmp, unsigned int num, t_hexinfo info)
{
	int	written;

	written = 0;
	if (!tab->zero || tab->precision >= 0)
		written += putchar_n(' ', info.padding);
	if (tab->zero && tab->precision < 0)
	{
		if (info.prefix)
			written += print_prefix(num, info.upper, info.prefix);
		written += putchar_n('0', info.padding);
	}
	if (!tab->zero || tab->precision >= 0)
		written += print_prefix(num, info.upper, info.prefix);
	written += print_main(tmp, info.len, info.zeros);
	return (written);
}
