/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/30 12:40:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_hex_digits(unsigned int n)
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

static void	fill_hex_string(char *s, unsigned int n, char *digits, int len)
{
	int	i;

	i = len;
	while (i > 0)
	{
		i--;
		s[i] = digits[n % 16];
		n /= 16;
	}
}

static char	*ft_hextoa(unsigned int n, int upper)
{
	char	*digits;
	char	*s;
	int		len;

	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = count_hex_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	else
		fill_hex_string(s, n, digits, len);
	return (s);
}

static t_hexinfo	compute_hexinfo(t_print *tab, unsigned int num, int upper,
		int len)
{
	t_hexinfo	info;

	info.upper = upper;
	info.len = len;
	if (tab->precision == 0 && num == 0)
		info.len = 0;
	info.zeros = 0;
	if (tab->precision > info.len)
		info.zeros = tab->precision - info.len;
	info.prefix = 0;
	if (tab->hash && num != 0)
		info.prefix = 2;
	info.padding = tab->width - (info.len + info.zeros + info.prefix);
	if (info.padding < 0)
		info.padding = 0;
	return (info);
}

int	hex_case(t_print *tab, const char *c)
{
	char			*tmp;
	unsigned int	num;
	t_hexinfo		info;
	int				written;
	int				len;

	num = va_arg(tab->args, unsigned int);
	if (*c == 'X')
		info.upper = 1;
	else
		info.upper = 0;
	tmp = ft_hextoa(num, info.upper);
	if (!tmp)
		return (0);
	len = ft_strlen(tmp);
	if (tab->precision == 0 && num == 0)
		tmp[0] = '\0';
	info = compute_hexinfo(tab, num, info.upper, len);
	if (tab->dash)
		written = print_hex_left(tmp, num, info);
	else
		written = print_hex_right(tab, tmp, num, info);
	free(tmp);
	tab->total_length += written;
	return (written);
}
