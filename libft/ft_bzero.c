/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiannis <yiannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:13:03 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/09 23:22:08 by yiannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
		*tmp++ = '\0';
}

// #include <stdio.h>

// int main(void)
// {
//     char s[10] = "paok";
//     int n = 2;
//     char *p = s + n;
//     ft_bzero(s, n);
//     printf("%s", s);
//     printf("%s", p);
// }