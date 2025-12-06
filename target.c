/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:09:03 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 18:12:20 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*find_closest_smaller(int value, t_stack stack_b)
{
	t_node	*b;
	t_node	*target;
	int		len_b;

	target = NULL;
	len_b = stack_size(stack_b);
	b = stack_b;
	while (len_b--)
	{
		if (b->data < value)
		{
			if (!target || b->data > target->data)
				target = b;
		}
		b = b->next;
	}
	return (target);
}

// closest smaller
void	target_in_b(t_stack stack_a, t_stack stack_b)
{
	t_node	*a;
	int		len_a;
	t_node	*target;

	a = stack_a;
	len_a = stack_size(stack_a);
	while (len_a--)
	{
		target = find_closest_smaller(a->data, stack_b);
		if (!target)
			target = max_node(stack_b);
		a->target = target;
		a = a->next;
	}
}

t_node	*find_cloest_bigger(int value, t_stack stack_a)
{
	t_node	*a;
	int		len_a;
	t_node	*target;

	target = NULL;
	len_a = stack_size(stack_a);
	a = stack_a;
	while (len_a--)
	{
		if (a->data > value)
		{
			if (!target || a->data < target->data)
				target = a;
		}
		a = a->next;
	}
	return (target);
}

// closest bigger
void	target_in_a(t_stack stack_b, t_stack stack_a)
{
	int		len_b;
	t_node	*b;
	t_node	*target;

	b = stack_b;
	len_b = stack_size(stack_b);
	while (len_b--)
	{
		target = find_cloest_bigger(b->data, stack_a);
		if (!target)
			target = min_node(stack_a);
		b->target = target;
		b = b->next;
	}
}
