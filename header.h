/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:16:02 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/06 18:11:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "printf/ft_printf_bonus.h"
# include "printf/libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				distance;
	struct s_node	*target;
	int				cost;
	int				after_median;
}					t_node;

typedef t_node		*t_stack;

void				push_swap(t_stack *stack_a, t_stack *stack_b);
void				free_up(t_node *head);
void				createlist(int n, char *arr[], t_stack *stack);
void				displaystack(t_stack stack);
t_node				*deletion(t_stack *stack);
void				insert(t_stack *stack, t_node *newnode);
void				swap_first_sec(t_stack *stack);
void				swap_firsts(t_stack *stack_a, t_stack *stack_b);
void				shift_up(t_stack *stack);
void				shift_down(t_stack *stack);
int					is_number(char *str);
void				sort_three(t_stack *stack_a);
void				push_back_to_a(t_stack *stack_a, t_stack *stack_b);
void				push_to_b(t_stack *stack_a, t_stack *stack_b);
int					stack_size(t_stack stack);
int					stack_sorted(t_stack *stack);
void				target_in_b(t_stack stack_a, t_stack stack_b);
void				target_in_a(t_stack stack_b, t_stack stack_a);
t_node				*cost_to_b(t_stack stack_a, t_stack stack_b);
t_node				*cost_to_a(t_stack stack_a, t_stack stack_b);
void				insert_after_target(t_stack *stack, t_node *node,
						t_node *target);
t_node				*min_node(t_stack stack);
void				distance_to_head(t_stack *stack);
void				rotate_node_to_top(t_stack *stack, t_node *node,
						char stack_name);
void				rotate_min_to_top(t_stack *stack_a);
void				initial_push_to_b(t_stack *stack_a, t_stack *stack_b);
void				push_all_but_three(t_stack *stack_a, t_stack *stack_b);
void				push_back_all(t_stack *stack_a, t_stack *stack_b);
t_node				*max_node(t_stack stack);
t_node				*find_closest_smaller(int value, t_stack stack_b);
t_node				*find_closest_bigger(int value, t_stack stack_a);

#endif
