/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:26:20 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 18:02:28 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newnode;
	void	*newcontent;

	head = NULL;
	if (!lst || !f)
	{
		return (NULL);
	}
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			if (del)
				del(newcontent);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, newnode);
		lst = lst->next;
	}
	return (head);
}

// #include <assert.h>
// #include <stdio.h>

// void	*f(void *content)
// {
// 	int	*newdata;

// 	newdata = content;
// 	newdata = malloc(sizeof(int));
// 	if (!newdata)
// 		return (NULL);
// 	*newdata = 99;
// 	return (newdata);
// }

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	int		i;
// 	int		*val;
// 	t_list	*lst1;
// 	t_list	*lst2;

// 	lst1 = NULL;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		val = malloc(sizeof(int));
// 		if (!val)
// 			return (1);
// 		*val = i;
// 		ft_lstadd_back(&lst1, ft_lstnew(val));
// 		i++;
// 	}
// 	assert(ft_lstsize(lst1) == 4);
// 	lst2 = ft_lstmap(lst1, &f, del);
// 	assert(ft_lstsize(lst2) == 4);
// 	while (lst2)
// 	{
// 		assert(*(int *)lst2->content == 99);
// 		lst2 = lst2->next;
// 	}
// 	printf("bellissima");
// 	return (0);
// }
