/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:06:22 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/16 12:39:44 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

// #include <assert.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int *val;
// 	t_list *head = NULL;
// 	int i = 0;

// 	while (i < 4)
// 	{
// 		val = malloc(sizeof(int));
// 		if (!val)
// 			return (1);
// 		*val = i;
// 		ft_lstadd_back(&head, ft_lstnew(val));
// 		i++;
// 	}
// 	assert(ft_lstsize(head) == 4);
// 	head = ft_lstlast(head);
// 	assert(*(int *)head->content == 3);
// 	printf("%d greaaaaat job", *(int *)head->content);
// }