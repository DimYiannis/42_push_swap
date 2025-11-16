/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/22 10:03:59 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int	count_digits(unsigned int n)
{
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigneditoa(unsigned int n)
{
	char			*s;
	unsigned int	len;

	len = count_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

int	ft_hexputnbr(unsigned long long n, int upper)
{
	char	*digits;
	int		len;

	len = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_hexputnbr(n / 16, upper);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

int	ft_addressputnbr(void *p)
{
	uintptr_t	addr;
	int			len;

	addr = (uintptr_t)p;
	if (!addr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_hexputnbr(addr, 0);
	return (len + 2);
}
