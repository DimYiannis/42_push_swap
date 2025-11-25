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

