/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:26:27 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/14 12:10:15 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

// #include <fcntl.h>

// int main(void)
// {
//     char s[] = "hello";
//     int fd = open("test.txt", O_WRONLY | O_TRUNC);
//     ft_putstr_fd(s, fd);
//     close(fd);
// }