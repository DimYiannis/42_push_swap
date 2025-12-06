/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:58:11 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 16:21:26 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate_node_to_top(t_stack *stack, t_node *node, char stack_name)
{
  int i;

  i = 0;
  if (node->after_median)
  {
    while (i < node->distance)
    {
      shift_down(stack);
      ft_printf("rr%c\n", stack_name);
      i++;
    }
  }
  else 
  {
    while (i < node->distance)
    {
      shift_up(stack);
      ft_printf("r%c\n", stack_name);
      i++;
    }
  }
}

void rotate_min_to_top(t_stack *stack_a)
{
  t_node *min;

  min = min_node(*stack_a);
  distance_to_head(stack_a);
  rotate_node_to_top(stack_a, min, 'a');
}

void initial_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
  while (stack_size(*stack_b) < 3)
    push_to_b(stack_a, stack_b);
  if ((*stack_b)->data > (*stack_b)->next->data)
  {
    shift_up(stack_b);
    ft_printf("rb\n");
  }
}

void push_all_but_three(t_stack *stack_a, t_stack *stack_b)
{
  t_node *cheapest;

  while (stack_size(*stack_a) > 3)
  {
    cheapest = cost_to_b(*stack_a, *stack_b);
    rotate_node_to_top(stack_a, cheapest, 'a');
    push_to_b(stack_a, stack_b);
  }
}

void push_back_all(t_stack *stack_a, t_stack *stack_b)
{
  t_node *cheapest;

  while (stack_size(*stack_b) > 0)
  {
    cheapest = cost_to_a(*stack_a, *stack_b);
    rotate_node_to_top(stack_b, cheapest, 'b');
    rotate_node_to_top(stack_a, cheapest->target, 'a');
    push_back_to_a(stack_a, stack_b);
  }
}


