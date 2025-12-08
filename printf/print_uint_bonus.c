/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:52 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:28:41 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	getting_padding(t_print *tab, int len)
{
	int	padding;

	padding = tab->width - (len + tab->is_zero);
	if (padding < 0)
		padding = 0;
	return (padding);
}

static int	print_left(t_print *tab, char *tmp, int len, int padding)
{
	int	written;

	written = putchar_n('0', tab->is_zero);
	written += putstring_n(tmp, len);
	written += putchar_n(' ', padding);
	return (written);
}

static int	print_right(t_print *tab, char *tmp, int len, int padding)
{
	int	written;

	written = 0;
	if (!tab->zero || tab->precision >= 0)
		written += putchar_n(' ', padding);
	else
		written += putchar_n('0', padding);
	written += putchar_n('0', tab->is_zero);
	written += putstring_n(tmp, len);
	return (written);
}

static int	prec(t_print *tab, char *tmp, unsigned int num)
{
	int	len;

	len = ft_strlen(tmp);
	if (tab->precision == 0 && num == 0)
	{
		len = 0;
		tmp[0] = '\0';
	}
	if (tab->precision > len)
		tab->is_zero = tab->precision - len;
	else
		tab->is_zero = 0;
	return (len);
}

int	unsigned_case(t_print *tab)
{
	unsigned int	num;
	char			*tmp;
	int				len;
	int				padding;
	int				written;

	num = va_arg(tab->args, unsigned int);
	tmp = ft_unsigneditoa(num);
	if (!tmp)
		return (0);
	len = prec(tab, tmp, num);
	padding = getting_padding(tab, len);
	if (tab->dash)
		written = print_left(tab, tmp, len, padding);
	else
		written = print_right(tab, tmp, len, padding);
	free(tmp);
	tab->total_length += written;
	return (written);
}
