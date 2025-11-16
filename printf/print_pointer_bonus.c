/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:30:19 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_ptrputnbr(unsigned long n)
{
	char	*digits;
	int		len;

	len = 0;
	digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_ptrputnbr(n / 16);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

static int	count_hex_digits(uintptr_t n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static int	print_null(t_print *tab)
{
	int	padding;
	int	len;

	len = 5;
	padding = 0;
	if (tab->width > len)
		padding = tab->width - len;
	if (tab->dash)
	{
		write(1, "(nil)", 5);
		len += putchar_n(' ', padding);
	}
	else
	{
		len += putchar_n(' ', padding);
		write(1, "(nil)", 5);
	}
	tab->total_length += len;
	return (len);
}

static int	print_addr(t_print *tab, uintptr_t addr)
{
	int	padding;
	int	written;
	int	addr_len;

	addr_len = 2 + count_hex_digits(addr);
	padding = 0;
	if (tab->width > addr_len)
		padding = tab->width - addr_len;
	written = 0;
	if (tab->dash)
	{
		written += write(1, "0x", 2);
		written += ft_ptrputnbr(addr);
		written += putchar_n(' ', padding);
	}
	else
	{
		written += putchar_n(' ', padding);
		written += write(1, "0x", 2);
		written += ft_ptrputnbr(addr);
	}
	return (written);
}

int	pointer_case(t_print *tab)
{
	void		*ptr;
	uintptr_t	addr;
	int			written;

	written = 0;
	ptr = va_arg(tab->args, void *);
	if (!ptr)
		return (print_null(tab));
	addr = (uintptr_t)ptr;
	written = print_addr(tab, addr);
	tab->total_length += written;
	return (written);
}
