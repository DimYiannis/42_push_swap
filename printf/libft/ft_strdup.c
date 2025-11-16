/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:58:34 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/09 16:20:11 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	s2 = s2 - len;
	return (s2);
}

// #include <stdio.h>

// int main(void)
// {
//     const char s1[10] = "wazzup";
//     char *duplicate = ft_strdup(s1);
//     printf("%s\n", s1);
//     printf("%s", duplicate);
// }