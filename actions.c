/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:39:12 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:47:23 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push_to_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp; 

  if (!stack_a || !*stack_a)
    return;
  tmp = deletion(stack_a);
  if (!tmp)
   return;
  insert(stack_b, tmp);
  ft_printf("pb\n");
}

void push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
  t_node *tmp; 
  if (!stack_b || !*stack_b)
    return;
  while (*stack_b)
  {
    tmp = deletion(stack_b);
    if (!tmp)
      break;
    insert(stack_a, tmp);
    ft_printf("pa\n");
    
  }
}

void swap_first_sec(t_stack *stack)
{
  int tmp_val;
    
  if (!stack || !*stack || (*stack)->next == *stack)
    return;
  tmp_val = (*stack)->data;
  (*stack)->data = (*stack)->next->data;
  (*stack)->next->data = tmp_val;
}

void swap_firsts(t_stack *stack_a, t_stack *stack_b)
{
  int tmp_val;

  tmp_val = (*stack_a)->data;
  (*stack_a)->data = (*stack_b)->data;
  (*stack_b)->data = tmp_val;
}
