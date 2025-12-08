/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:29:25 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/15 10:16:41 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// #include <stdio.h>

// void del(void *content)
// {
//     (void)content;
// }

// #include <assert.h>

// int	main(void)
// {
// 	t_list *lst = ft_lstnew((void *)0);
// 	assert(lst->next == NULL);
// 	assert(ft_lstsize(lst) == 1);
// 	ft_lstadd_back(&lst, ft_lstnew((void *)1));
// 	ft_lstadd_back(&lst, ft_lstnew((void *)2));
// 	ft_lstadd_back(&lst, ft_lstnew((void *)3));
//     assert(ft_lstsize(lst) == 4);
//     ft_lstclear(&lst, del);
//     assert(lst == NULL);
//     assert(ft_lstsize(lst) == 0);

//     printf("nada problemo");
// }