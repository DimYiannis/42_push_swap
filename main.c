/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:52:06 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 17:21:52 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	createlist(argc, argv, &stack_a);
	if (!stack_a)
		return (1);
	push_swap(&stack_a, &stack_b);
	if (stack_a != NULL)
		free_up(stack_a);
	return (0);
}
