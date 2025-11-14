/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiannis <yiannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:29:50 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/12 22:57:20 by yiannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s1[] = "paokara";
// 	char s2[] = ft_calloc(strlen(s1) + 1, sizeof(char));
// 	printf("%s", s2);
// 	free(s2);
// 	return (0);
// }

// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void)
// {
//     size_t count = SIZE_MAX;
//     size_t size = 2;

//     size_t total = count * size;
//     printf("Requested allocation: %zu bytes\n", count * size);
//     printf("Wrapped-around total: %zu bytes\n", total);

//     char *ptr = malloc(total);
//     if (!ptr)
//     {
//         printf("Malloc failed\n");
//         return (1);
//     }

//     size_t i;
//     for (i = 0; i < 10; i++)
//     {
//         ptr[i] = 'A';
//         printf("Writing ptr[%zu]\n", i);
//     }

//     printf("First byte: %c\n", ptr[0]);

//     free(ptr);
//     return (0);
// }
