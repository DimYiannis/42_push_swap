/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:20:40 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:51:22 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
  int len;
  
  if (!stack_a || !*stack_a)
      return;
  len = stack_len(*stack_a);
  if (len <= 3)
  {
    sort_three(stack_a);
    return;
  }
  while (stack_size(*stack_b) < 3)
    push_to_b(stack_a, stack_b);
  if ((*stack_b)->data > (*stack_b)->next->data)
    shift_up(stack_b);
  while (stack_size(*stack_a) > 3)
    push_to_b(cost(*stack_a, *stack_b), stack_b);
  sort_three(stack_a);
  push_back_to_a(stack_a, stack_b);
}

