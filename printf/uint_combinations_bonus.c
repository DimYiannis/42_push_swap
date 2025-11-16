/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_combinations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/29 09:32:59 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	count_decimal_digits(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
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

	len = count_decimal_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (len > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
