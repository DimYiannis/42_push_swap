/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:20:40 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 17:22:35 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	if (!stack_a || !*stack_a)
		return ;
	len = stack_size(*stack_a);
	if (stack_sorted(stack_a))
		return ;
	if (len <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	initial_push_to_b(stack_a, stack_b);
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	push_back_all(stack_a, stack_b);
	rotate_min_to_top(stack_a);
}
