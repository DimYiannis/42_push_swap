/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:37:24 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/09 10:24:50 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	lencpy;
	char	*pdst;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	if (dstsize <= lendst)
	{
		return (dstsize + lensrc);
	}
	lencpy = dstsize - lendst - 1;
	pdst = dst + lendst;
	while (*src && lencpy--)
	{
		*pdst++ = *src++;
	}
	*pdst = '\0';
	return (lendst + lensrc);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char a[] = "1337 42";
// 	char b[] = "Born to code";

// 	ft_strlcat(a, b, 20);
// 	printf("%s", a);
// }