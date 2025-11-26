/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:22 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:47:38 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sort_three(t_stack *stack_a)
{
  int first; 
  int second; 
  int third;

  if (!*stack_a || (*stack_a)->next == *stack_a)
      return;
  if ((*stack_a)->next->next == *stack_a && (*stack_a->data < stack_a->next->data))
  {
    shift_up(stack_a);
    ft_printf("ra\n");
  }
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

void shift_up(t_stack *stack)
{
  *stack = (*stack)->next;
}

void shift_down(t_stack *stack)
{
  *stack = (*stack)->prev;
}
