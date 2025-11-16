/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:35:31 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 22:07:35 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

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

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	num;
	int		sign;

	sign = 0;
	num = n;
	if (n < 0)
	{
		num = -num;
		sign = 1;
	}
	len = count_digits((int)num) + sign;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = num % 10 + '0';
		num /= 10;
		if (sign == 1 && len == 0)
			s[0] = '-';
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
//  	printf("%s\n", ft_itoa(111));
//  	printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(5));
//     printf("%s\n", ft_itoa(-5));
//     printf("%s\n", ft_itoa(12345));
//     printf("%s\n", ft_itoa(-12345));
//     printf("%s\n", ft_itoa(-2147483648));
// }