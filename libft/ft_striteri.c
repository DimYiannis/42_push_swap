/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:20:16 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/14 12:10:55 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void a_b(unsigned int n, char *s)
// {
//     if (n % 2 == 0)
//         *s = ft_toupper(*s);
// }

// int main(void)
// {
//     char s[] = "heloooooo";
//      ft_striteri(s, a_b);
//     printf("%s",s);
//     return (0);
// }