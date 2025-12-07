/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:22 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 18:42:20 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap_and_print(t_stack *stack_a)
{
  swap_first_sec(stack_a);
  ft_printf("sa\n");
}

void sort_two(t_stack *stack)
{
  if (stack_size(*stack) == 2)
  {
    if ((*stack)->data > (*stack)->next->data)
     swap_and_print(stack);
  }
}

void	sort_three(t_stack *stack_a)
{
	t_node	*max;

	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
  if (stack_size(*stack_a) == 2)
  {
    sort_two(stack_a);
    return;
  }
  max = max_node(*stack_a);
	if (*stack_a == max)
  {
    shift_up(stack_a);
    ft_printf("ra\n");
  }
	else if ((*stack_a)->next == max)
  {
    shift_down(stack_a);
    ft_printf("rra\n");
  }	
  if ((*stack_a)->data > (*stack_a)->next->data)
    swap_and_print(stack_a);
}

void	shift_up(t_stack *stack)
{
	*stack = (*stack)->next;
}

void	shift_down(t_stack *stack)
{
	*stack = (*stack)->prev;
}
