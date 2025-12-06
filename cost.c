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
  t_node *a;
  int len_a;
  int len_b;
  t_node *b;
  t_node *target;

  a = stack_a;
  len_a = stack_size(stack_a); 
  while (len_a--)
  {
    target = NULL;
    len_b = stack_size(stack_b);
    b = stack_b;
    while (len_b--)
    {
      if (b->data < a->data)
      {
        if (!target || b->data > target->data)
          target = b;
      }
      b = b->next;
    }
    if (!target)
      target = max_node(stack_b);
    a->target = target;
    a = a->next;
  }
 }

// closest bigger
void target_in_a(t_stack stack_b, t_stack stack_a)
{
  int len_a;
  int len_b;
  t_node *a;
  t_node *b;
  t_node *target;

  b = stack_b;
    len_b = stack_size(stack_b);
  while (len_b--)
  {
    target = NULL;
    len_a = stack_size(stack_a);
    a = stack_a;
    while (len_a--)
    {
      if (a->data > b->data)
      {
        if (!target || a->data < target->data)
          target = a;
      }
      a = a->next;
    }
    if (!target)
      target = min_node(stack_a);
    b->target = target;
    b = b->next;
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
  while (i < stack_len)
  {
    if (i <= median) 
    {
      tmp->distance = i;
      tmp->after_median = 0;
    }
    else 
    {
      tmp->distance = stack_len - i;
      tmp->after_median = 1;
    }
    tmp = tmp->next;
    i++;
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
  target_in_b(stack_a, stack_b);
  while (i < len)
  {
    stack_a->cost = stack_a->distance + stack_a->target->distance;
    if (result->cost > stack_a->cost)
      result = stack_a;
    stack_a = stack_a->next;
    i++;
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
  target_in_a(stack_b, stack_a); 
  while (i < len)
  {
    stack_b->cost = stack_b->distance + stack_b->target->distance;
    if (result->cost > stack_b->cost)
      result = stack_b;
    stack_b = stack_b->next;
    i++;
  }
  return (result);
}
