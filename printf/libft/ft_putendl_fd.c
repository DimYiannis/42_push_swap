/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:47:33 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/14 12:09:52 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// #include <fcntl.h>

// int main(void)
// {
//     char s[] = "hellooo";
//     int fd = open("test.txt", O_WRONLY | O_TRUNC);
//     ft_putendl_fd(s, fd);
//     close(fd);
// }
