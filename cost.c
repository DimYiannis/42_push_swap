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
  len = stack_size(stack);
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

t_node *min_node(t_stack stack)
{
  int len;
  int i;
  t_stack min;

  i = 0;
  if (!stack)
    return (NULL);
  len = stack_size(stack);
  min = stack;
  while (i < len)
  {
    if (stack->data < min->data)
      min = stack;
    stack = stack->next;
    i++;
  }
  return (min);
}

// closest smaller
void target_in_b(t_stack stack_a, t_stack stack_b)
{
  int i;
  int len;

  i = 0;
  len = stack_size(stack_b);
  if (!stack_a  || !stack_b)
    return;
  while (i < len)
  {
    if (stack_a->data > stack_b->data)
    {
      stack_a->target = stack_b;
      stack_b = stack_b->next;
      if (stack_b->data > stack_a->target->data)
        stack_a->target = stack_b;
    }
    else
    { 
      stack_b = stack_b->next;
      if (i == len - 1)
        stack_a->target = max_node(stack_b);
    }
    i++;
  }
}

// closest bigger
void target_in_a(t_stack stack_a, t_stack stack_b)
{
  int i;
  int len;

  i = 0;
  len = stack_size(stack_b);
  if (!stack_a  || !stack_b)
    return;
  while (i < len)
  {
    if (stack_a->data < stack_b->data)
    {
      stack_a->target = stack_b;
      stack_b = stack_b->next;
      if (stack_b->data < stack_a->target->data)
        stack_a->target = stack_b;
    }
    else
    { 
      stack_b = stack_b->next;
      if (i == len - 1)
        stack_a->target = min_node(stack_b);
    }
    i++;
  }
}


void distance_to_head(t_stack *stack)
{
  int stack_len;
  int median;
  int i;
  t_node *tmp;

  tmp = *stack;
  i = 0;
  stack_len = (stack_size(*stack));
  median = stack_len / 2;
  if (stack_len % 2 == 0)
  {
    while (i <= median)
    {
      tmp->distance = i;
      tmp->after_median = 0;
      tmp = tmp->next;
      i++;
    }
    i = 0;
    tmp = *stack;
    while (i < median)
    {
      tmp->distance = i;
      tmp->after_median = 1;
      tmp = tmp->prev;
      i++;
    }
  }
  else if (stack_len % 2 != 0)
  {
     while (i <= median)
    {
      tmp->distance = i;
      tmp->after_median = 0;
      tmp = tmp->next;
      if (i == median)
        tmp->next->distance = median;
      i++;
    }
    i = 0;
    tmp = *stack;
    while (i < median)
    {
      tmp->distance = i;
      tmp->after_median = 1;
      tmp = tmp->prev;
      i++;
    }
  }
}

t_node *cost_to_b(t_stack stack_a, t_stack stack_b)
{
  int i;
  int len;
  t_node *result;

  i = 0;
  len = stack_size(stack_a);
  result = stack_a;
  distance_to_head(&stack_a);
  distance_to_head(&stack_b);
  while (i < len)
  {
    target_in_b(stack_a, stack_b);
    stack_a->cost = stack_a->distance + stack_a->target->distance;
    if (result->cost > stack_a->cost)
      result = stack_a;
    stack_a = stack_a->next;
  }
  return (result);
}

t_node *cost_to_a(t_stack stack_a, t_stack stack_b)
{
  int i;
  int len;
  t_node *result;

  i = 0;
  len = stack_size(stack_b);
  result = stack_b;
  distance_to_head(&stack_b);
  distance_to_head(&stack_a);
  while (i < len)
  {
    target_in_a(stack_b, stack_a);
    stack_b->cost = stack_b->distance + stack_b->target->distance;
    if (resut->cost > stack_b)
      result = stack_b;
    stack_b = stack_b->next;
  }
  return (result);
}
