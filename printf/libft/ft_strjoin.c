/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiannis <yiannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 22:43:45 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/12 22:55:53 by yiannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	string = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!string)
		return (NULL);
	while (i < len1)
	{
		string[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}

// #include <stdio.h>

// int main()
// {
//     char s1[] = "hello";
//     char s2[] = "world";
//     printf("%s", ft_strjoin(s1, s2));
// }