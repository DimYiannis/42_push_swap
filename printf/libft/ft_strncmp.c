/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiannis <yiannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:05:38 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/12 22:45:35 by yiannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char s1[6] = "paokaa";
// 	char s2[6] = "paokaq";
// 	printf("%d", ft_strncmp(s1, s2, 6));
// 	printf("%d", strncmp(s1, s2, 6));
// }