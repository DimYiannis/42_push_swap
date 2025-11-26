/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:04:34 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


t_node *deletion(t_stack *stack)
{
  t_node *tmp;
  t_node *last;
 
  if (!stack || !*stack)
    return (NULL);
  tmp = *stack;
  if (tmp->next == tmp)
  {
    *stack = NULL;
    tmp->next = tmp->prev = tmp;
    return tmp;
  }
  last = tmp->prev;

  last->next = tmp->next;
  tmp->next->prev = last;

  *stack = tmp->next;

  tmp->next = tmp->prev = tmp;
  return (tmp);
}

void insert(t_stack *stack, t_node *newnode)
{
  t_node *last;

  if (!stack || !newnode)
    return;
   if (!*stack)
  {
    newnode->next = newnode;
    newnode->prev = newnode;
    *stack = newnode;
    return;
  }
  last = (*stack)->prev;
  newnode->next = *stack;
  newnode->prev = last;
  last->next = newnode;
  (*stack)->prev = newnode;
  *stack = newnode;
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

void shift_up(t_stack *stack)
{
  *stack = (*stack)->next;
}

void shift_down(t_stack *stack)
{
  *stack = (*stack)->prev;
}



