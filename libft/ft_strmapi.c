/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:17:34 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/14 12:11:14 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*result;
	unsigned int	i;

	i = 0;
	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

// #include <stdio.h>

// char a_b(unsigned int n, char s)
// {
//     if (n % 2 == 0)
//         s = ft_toupper(s);
//     return (s);
// }

// int main(void)
// {
//     char *s = "heloooooo";
//     printf("%s", ft_strmapi(s, a_b));
// }