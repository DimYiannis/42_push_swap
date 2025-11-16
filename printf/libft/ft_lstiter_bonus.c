/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:22:36 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 10:56:18 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (!lst || !f)
		return ;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

// #include <assert.h>
// #include <stdio.h>

// void	f(void *content)
// {
// 	*(int *)content = 99;
// }

// int	main(void)
// {
// 	int i = 0;
// 	t_list *lst = ft_lstnew(&i);
//     i++;
// 	while (i < 4)
// 	{
// 		ft_lstadd_back(&lst, ft_lstnew(&i));
//         i++;
// 	}
// 	assert(ft_lstsize(lst) == 4);
// 	assert(lst->next->next->next->next == NULL);
// 	ft_lstiter(lst, f);
// 	t_list *tmp = lst;
// 	while (tmp)
// 	{
// 		assert(*(int *)tmp->content == 99);
// 		tmp = tmp->next;
// 	}
//     printf("perfecto");
// }