/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 18:34:55 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*deletion(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack)
		return (NULL);
	tmp = *stack;
	if (tmp->next == tmp)
	{
		*stack = NULL;
		tmp->next = tmp;
		tmp->prev = tmp;
		return (tmp);
	}
	last = tmp->prev;
	last->next = tmp->next;
	tmp->next->prev = last;
	*stack = tmp->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	insert(t_stack *stack, t_node *newnode)
{
	t_node	*last;

	if (!stack || !newnode)
		return ;
	if (!*stack)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*stack = newnode;
		return ;
	}
	last = (*stack)->prev;
	newnode->next = *stack;
	newnode->prev = last;
	last->next = newnode;
	(*stack)->prev = newnode;
	*stack = newnode;
}

void	displaystack(t_stack stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (1)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}

