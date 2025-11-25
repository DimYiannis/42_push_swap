/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:38:55 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void deletion(t_stack *stack)
{
  t_node *tmp;
  t_node *last;
 
  if (!stack || !*stack)
    return;
  tmp = *stack;
  if (tmp == tmp->next)
  {
    free(tmp);
    *stack = NULL;
    return;
  }
  last = tmp->prev; 
  last->next = tmp->next;
  (*stack) = (*stack)->next;
  (*stack)->prev = last;
  free(tmp);
}

void insert(t_stack *stack, t_stack newnode)
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
  t_node *tmp;
    
  if (stack && *stack && (*stack)->next)
  {
    int tmp_val = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = tmp_val;
  }
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


int is_number(char *str)
{
  int i;

  i = 0;
  if (!str || str[0] == '\0')
    return (0);
  if (str[0] == '-' || str[0] == '+')
    i++;
  while (str[i])
  {
    if (!ft_isdigit((unsigned char)str[i]))
      return (0);
    i++;
  }
  return (1);
}
