/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:56:32 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/08 10:38:52 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			n;

	tmp = (unsigned char *)b;
	n = 0;
	while (n < len)
	{
		*tmp++ = (unsigned char)c;
		n++;
	}
	return (b);
}

// #include <stdio.h>

// int main(void)
// {
//     int x = 'a';
//     char s[10] = "paok";
//     ft_memset(s, x, 3);
//     printf("%s", s);
// }