/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiannis <yiannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:44:14 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/12 22:12:43 by yiannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	const char	*ptr;

	src_len = 0;
	ptr = src;
	while (*ptr++)
		src_len++;
	if (dstsize == 0)
		return (src_len);
	if (dstsize > src_len + 1)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char dest[5];
// 	size_t len = ft_strlcpy(dest, "paokara", sizeof(dest));
// 	printf("dest = \"%s\", returned len = %zu\n", dest, len);
// }
