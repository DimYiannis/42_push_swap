/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:15:58 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/16 14:05:18 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

static int	ft_isnum(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	counter;

	counter = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		counter++;
		str++;
	}
	while (ft_isnum(*str) == 1)
	{
		num = num * 10;
		num = num + (*str - 48);
		str++;
	}
	if (counter > 1)
		return (0);
	return (num * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int val;
// 	char *str;
// 	str = "+945";
// 	val = ft_atoi(str);
// 	printf("integral number = %d \n", val);
// 	val = atoi(str);
// 	printf("integral number = %d", val);
// }