/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:44:08 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/14 19:50:00 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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
//     printf("%d \n",ft_lstsize(lst));
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
// 			tmp = tmp->next;
//     }

// }

// int	main(void)
// {
//     t_list *lst = malloc(sizeof(t_list));
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
//     lst->next = NULL;
// 	creatlist(4, lst);
//     display_list(lst);
// }