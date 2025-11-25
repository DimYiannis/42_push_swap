/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:39:12 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:39:35 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int stack_size(t_stack stack)
{
  t_node *tmp;
  int count = 0;

  if (!stack)
    return 0;
  tmp = stack;
  count++;
  tmp = tmp->next;
  while (tmp != stack)
  {
    count++;
    tmp = tmp->next;
  }
  return (count);
}
void push_to_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp; 

  if (!stack_a || !*stack_a)
    return;
  while (stack_size(*stack_a) > 3)
  {
    tmp = deletion(stack_a);
    if (!tmp)
      break;
    insert(stack_b, tmp);
    ft_printf("pb\n");

  }
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

void sort_three(t_stack *stack_a)
{
  int first; 
  int second; 
  int third;

    if (!*stack_a || (*stack_a)->next == *stack_a || (*stack_a)->next->next == *stack_a)
        return;

    first = (*stack_a)->data;
    second = (*stack_a)->next->data;
    third = (*stack_a)->next->next->data;

    if (first > second && second < third && first < third)
    {
        swap_first_sec(stack_a);
        ft_printf("sa\n");
    }
    else if (first > second && second > third)
    {
        swap_first_sec(stack_a);
        ft_printf("sa\n");
        shift_down(stack_a);
        ft_printf("rra\n");
    }
    else if (first > second && second < third && first > third)
    {
        shift_up(stack_a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third && first < third)
    {
        swap_first_sec(stack_a);
        ft_printf("sa\n");
        shift_up(stack_a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third && first > third)
    {
        shift_down(stack_a);
        ft_printf("rra\n");
    }
}
