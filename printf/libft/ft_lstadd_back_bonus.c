/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:48:45 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 17:58:32 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

// #include <stdio.h>

// void	creatlist(int n, t_list *lst)
// {
// 	int	data;
// 	int	i;

// 	t_list *tmp, *newnode;
// 	data = 2;
// 	i = 1;

// 	*(int *) lst->content = data;
// 	lst->next = NULL;
// 	tmp = lst;
// 	while (i < n)
// 	{
// 		newnode = malloc(sizeof(t_list));
// 		if (!newnode)
// 		{
// 			printf("me alloc failed");
// 		}

//         newnode->content = malloc(sizeof(int));
//         if (!newnode->content)
//         {
//             printf("malloc failed for content\n");
//             free(newnode);
//             return ;
//         }

// 		*(int*) newnode->content = data;
// 		newnode->next = NULL;

// 		tmp->next = newnode;
// 		tmp = tmp->next;
//         i++;
// 	}
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
//         printf("%d", *(int *)tmp->content);
// 		tmp = tmp->next;
//     }

// }

// int	main(void)
// {
//     t_list *lst, *newnode;

//     lst = malloc(sizeof(t_list));
// 	if (lst == NULL)
// 	{
// 		printf("memory alloc failed \n");
// 	}
//     lst->content = malloc(sizeof(int));
//     if (lst->content == NULL)
//     {
//         printf("mem alloc failed");
//         free(lst);
//         return (1);
//     }
//     newnode = malloc(sizeof(t_list));
// 	if (newnode == NULL)
// 	{
// 		printf("memory alloc failed \n");
// 	}
//     newnode->content = malloc(sizeof(int));
// 	if (newnode->content == NULL)
// 	{
// 		printf("memory alloc failed \n");
// 	}
//     *(int *)newnode->content = 4;
//     lst->next = NULL;
// 	creatlist(4, lst);
//     ft_lstadd_back(&lst, newnode);
//     display_list(lst);
// }