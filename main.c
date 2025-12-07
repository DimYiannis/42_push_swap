/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:52:06 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/07 21:20:04 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**make_list(int n, char **str)
{
	int		i;
	char	**list;

	list = malloc(sizeof(char *) * (n + 2));
	if (!list)
	{
		free_split(str);
		printf("Error\n");
		return (NULL);
	}
	list[0] = "skip_this";
	i = 0;
	while (i < n)
	{
		list[i + 1] = str[i];
		i++;
	}
	list[n + 1] = NULL;
	return (list);
}

void	two_args(char *argv, t_stack *stack)
{
	char	**new_argv;
	char	**list;
	int		size;

	new_argv = ft_split(argv, ' ');
	if (!new_argv)
	{
		printf("Error\n");
		return ;
	}
	size = 0;
	while (new_argv[size])
		size++;
	list = make_list(size, new_argv);
	createlist(size + 1, list, stack);
	free(list);
	free_split(new_argv);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		two_args(argv[1], &stack_a);
	else
		createlist(argc, argv, &stack_a);
	if (!stack_a)
		return (1);
	if (stack_sorted(&stack_a))
		return (free_up(stack_a), 0);
	push_swap(&stack_a, &stack_b);
	if (stack_a != NULL)
		free_up(stack_a);
	if (stack_b != NULL)
		free_up(stack_b);
	return (0);
}
