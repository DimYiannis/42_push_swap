/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:00:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/17 19:06:33 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (pdst <= psrc)
	{
		while (len--)
			*pdst++ = *psrc++;
	}
	else if (pdst > psrc)
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len--)
		{
			*pdst-- = *psrc--;
		}
	}
	return (dst);
}

//  #include <stdio.h>

// int main(void)
// {
//     char s[10] = "paokara";
//     char str[100] = "Learningisfun";
//     ft_memmove(s + 2, s, 3);
//     printf("%s \n", s);
//     ft_memmove(str + 8, str, 10);
//     printf("memmove overlap : %s\n ", str);
// }