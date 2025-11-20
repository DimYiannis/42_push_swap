/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:52:06 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:44:30 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main (int argc, char *argv[])
{
  t_stack stack_a;
  t_stack stack_b;

  if (!argv)
    return ft_printf("Error\n");
  stack_a = NULL;
  stack_b = NULL;
  createlist(argc, argv, &stack_a);
  //implement logic
  //push_swap(stack_a, stack_b);

  //display actions

  //display stacks
  displaystack(stack_a);
  free(stack_a);
  return (0);
}
