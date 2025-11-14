/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:40:37 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/14 16:20:32 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*header;

	header = (struct s_list *)malloc(sizeof(t_list));
	if (!header)
		return (NULL);
	header->content = content;
	header->next = NULL;
	return (header);
}

// #include <stdio.h>

// void display_node(int n)
// {
// 	t_list *head;
// 	head = ft_lstnew(&n);
// 	printf("%d", *(int *)head->content);
// }

// int	main(void)
// {
// 	display_node(6);
// }