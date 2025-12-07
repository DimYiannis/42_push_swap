/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:16:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/07 21:19:57 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_node(char *str)
{
	t_node	*newnode;

	if (!str || !is_number(str))
		return (NULL);
	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = ft_atoi(str);
	newnode->distance = 0;
	return (newnode);
}

t_node	*init_first_node(char *str)
{
	t_node	*first;

	first = create_node(str);
	if (!first)
		return (NULL);
	first->next = first;
	first->prev = first;
	return (first);
}

void	add_rest_nodes(int n, char *arr[], t_stack *stack, t_node *tmp)
{
	t_node	*newnode;
	int		i;

	i = 2;
	while (i < n)
	{
		newnode = create_node(arr[i]);
		if (!newnode)
		{
			free_up(*stack);
			*stack = NULL;
			return ;
		}
		newnode->next = *stack;
		newnode->prev = tmp;
		tmp->next = newnode;
		(*stack)->prev = newnode;
		tmp = newnode;
		i++;
	}
}

void	createlist(int n, char *arr[], t_stack *stack)
{
	if (dup_vals(n, arr))
	{
		ft_printf("Error\n");
		*stack = NULL;
		return ;
	}
	*stack = init_first_node(arr[1]);
	if (!*stack)
	{
		ft_printf("Error\n");
		return ;
	}
	add_rest_nodes(n, arr, stack, *stack);
	if (!*stack)
		ft_printf("Error\n");
}
