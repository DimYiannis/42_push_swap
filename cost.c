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

t_node *target(t_stack *stack_a, t_stack *stack_b)
{
 if (!stack_a || !*stack_a || !stack_b || !*stack_b)
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
