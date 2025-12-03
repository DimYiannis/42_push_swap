/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:08:57 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/27 18:38:11 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

t_node *max_node(t_stack stack)
{
  int len;
  int i;
  t_stack max;

  i = 0;
  if (!stack)
    return (NULL);
  len = stack_len(stack);
  max = stack;
  while (i < len)
  {
    if (stack->data > max->data)
      max = stack;
    stack = stack->next;
    i++;
  }
  return (max);
}

t_node *target(t_stack stack_a, t_stack stack_b)
{
  t_stack target;
  int i;
  int len;

  i = 0;
  len = stack_len(stack_b);
  if (!stack_a || !*stack_a || !stack_b || !*stack_b)
    return (NULL);
  while (i < len)
  {
    if (stack_a->data > stack_b->data)
    {
      target = stack_b;
      stack_b = stack_b->next;
      if (stack_b->data > target->data)
      target = stack_b;
    }
    else
      target = max_node(stack_b);
  }
  return (target);
}


int distance_to_head(t_stack *stack)
{
  int distance;
  int stack_len;
  int median;
  int i;
  t_node *tmp;

  tmp = stack;
  i = 0;
  stack_len = (stack_size(&stack));
  distance = 0;
  median = stack_len / 2;
  if (stack_len % 2 = 0)
  {
    while (i <= median)
    {
      tmp->distance = i;
      tmp = tmp->next;
      i++;
    }
    i = 0;
    tmp = stack;
    while (i < median)
    {
      tmp->distance = i;
      tmp = tmp->prev;
      i++;
    }
  }
  else if (stack_len % 2 != 0)
  {
    // node->next->distance = median
     while (i <= median)
    {
      tmp->distance = i;
      tmp = tmp->next;
      if (i == median)
        tmp->next->distance = median;
      i++;
    }
    i = 0;
    tmp = stack;
    while (i < median)
    {
      tmp->distance = i;
      tmp = tmp->prev;
      i++;
    }

  }
}
