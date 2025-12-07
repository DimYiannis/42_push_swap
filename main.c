/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:52:06 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/07 15:43:46 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 3)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	createlist(argc, argv, &stack_a);
	if (!stack_a)
		return (1);
	if (stack_sorted(&stack_a))
	{
		free_up(stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b);
	if (stack_a != NULL)
		free_up(stack_a);
	if (stack_b != NULL)
		free_up(stack_b);
	return (0);
}
