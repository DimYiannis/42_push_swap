/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:59:41 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/09 10:24:35 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n--)
		*pdst++ = *psrc++;
	return (dst);
}

// #include <stdio.h>

// int main(void)
// {
//     char dst[10] = "aris";
//     char src[10] = "paok";
//     ft_memcpy(dst, src, 3);
//     printf("%s", dst);
// }