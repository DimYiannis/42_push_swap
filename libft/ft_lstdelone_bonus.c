/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:03 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 10:15:05 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// #include  <assert.h>

// void del(void *content)
// {
//     (void)content;
// }

// void	display_list(t_list *lst)
// {
// 	t_list	*tmp;
//     if (lst == NULL)
// 	{
// 		printf("list is empty");
// 	}

//     tmp = lst;
//     while (tmp != NULL)
//     {
//         printf("%p \n", tmp->content);
// 			tmp = tmp->next;
//     }

// }

// int	main(void)
// {
//     t_list *lst = ft_lstnew((void*)0);
//     assert(lst->next == NULL);
//     assert(ft_lstsize(lst) == 1);

//     ft_lstadd_back(&lst, ft_lstnew((void*)1));
//     ft_lstadd_back(&lst, ft_lstnew((void*)2));
//     ft_lstadd_back(&lst, ft_lstnew((void*)3));
//     assert(ft_lstsize(lst) == 4);

//     display_list(lst);

//     t_list *tmp = lst->next->next; //move 2 nodes
//     lst->next->next = tmp->next; // unlink from list
//     ft_lstdelone(tmp, del); //del

//     assert(ft_lstsize(lst) == 3);
//     printf("\n");
//     display_list(lst);

// }