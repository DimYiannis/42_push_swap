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


void push_to_b(t_stack *stack_a, t_stack *stack_b)
{
  while (*stack_a && (*stack_a)->next != *stack_a)
  {
    t_node *tmp = *stack_a;

    deletion(stack_a);
    insert(stack_b, tmp);

    ft_printf("pb\n");
  }
}

void push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
  while (*stack_b)
  {
    t_node *tmp = *b;
    deletion(b);
    insert(a, tmp);
    ft_printf("pa\n");
  }
}

void sort_three(t_stack *stack_a)
{
    int first, second, third;

    if (!*a || (*a)->next == *a || (*a)->next->next == *a)
        return; // 0 or 1 element, already sorted

    first = (*a)->data;
    second = (*a)->next->data;
    third = (*a)->next->next->data;

    // There are only 5 possible unsorted cases for 3 elements
    if (first > second && second < third && first < third)
    {
        swap_first_sec(a);
        ft_printf("sa\n");
    }
    else if (first > second && second > third)
    {
        swap_first_sec(a);
        ft_printf("sa\n");
        shift_down(a);
        ft_printf("rra\n");
    }
    else if (first > second && second < third && first > third)
    {
        shift_up(a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third && first < third)
    {
        swap_first_sec(a);
        ft_printf("sa\n");
        shift_up(a);
        ft_printf("ra\n");
    }
    else if (first < second && second > third && first > third)
    {
        shift_down(a);
        ft_printf("rra\n");
    }
}
