/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:30:12 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_padd_sign(t_print *tab, int padding, int neg)
{
	int	written;

	written = 0;
	if (!tab->dash && (!tab->zero || tab->precision > 0))
		written += putchar_n(' ', padding);
	if (neg)
		written += write(1, "-", 1);
	else if (tab->sign)
		written += write(1, "+", 1);
	else if (tab->sp)
		written += write(1, " ", 1);
	if (!tab->dash && tab->zero && tab->precision < 0)
		written += putchar_n('0', padding);
	return (written);
}

static int	prec(t_print *tab, char *tmp, int num)
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

static char	*get_int_string(long long *num, int *neg)
{
	char	*tmp;

	if (*num == INT_MIN)
	{
		tmp = ft_strdup("2147483648");
		*neg = 1;
	}
	else
	{
		*neg = handle_neg(num);
		tmp = ft_itoa((int)*num);
	}
	return (tmp);
}

int	int_case(t_print *tab)
{
	char			*tmp;
	long long int	num;
	int				len;
	int				written;
	int				neg;

	written = 0;
	num = va_arg(tab->args, int);
	tmp = get_int_string(&num, &neg);
	len = prec(tab, tmp, num);
	written = print_padd_sign(tab, get_padding(tab, len, neg), neg);
	written += print_num_space(tab, tmp, len, get_padding(tab, len, neg));
	free(tmp);
	tab->total_length += written;
	return (written);
}
