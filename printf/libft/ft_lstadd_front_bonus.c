/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:15 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 10:21:38 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// void	display_node(int n)
// {
// 	t_list	*head;
// 	t_list	*newnode;

// 	head = NULL;
// 	newnode = ft_lstnew(&n);
// 	ft_lstadd_front(&head, newnode);
// 	printf("%d", *(int *)head->content);
// 	head = head->next;
// }

// int	main(void)
// {
// 	display_node(4);
// }