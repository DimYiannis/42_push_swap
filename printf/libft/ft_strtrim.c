/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:00 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/13 10:32:25 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = malloc(end - start + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, end - start + 1);
	return (s2);
}

// #include <stdio.h>

// int main()
// {
//     const char s[] = "abcdefghijklmnopqrstuvwxyz";
//     const char set[] = "az";
//     char *res = ft_strtrim(s, set);
//     printf("%s", res);
//     free(res);
//     return (0);
// }