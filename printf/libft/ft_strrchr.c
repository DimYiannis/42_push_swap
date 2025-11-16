/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:29:05 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/17 20:15:10 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*index;
	unsigned char	ch;

	ch = (unsigned char)c;
	index = NULL;
	while (*s)
	{
		if (*s == ch)
			index = ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (index);
}

// #include <stdio.h>

// int main(void)
// {
//     char s[10] = "paokara";
//     char c = 'l';
//     printf("%s", ft_strrchr(s, c));
// }