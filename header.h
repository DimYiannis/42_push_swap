/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:16:02 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:42:30 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H
# include "printf/libft/libft.h"
# include "printf/ft_printf_bonus.h"

typedef struct s_node
{
  int data;
  struct s_node *next;
  struct s_node *prev;
} t_node;

typedef t_node *t_stack;

//void push_swap(struct node **stack_a, struct node **stack_b);
void	free_up(t_node *head);
void createlist(int n, char *arr[], t_stack *stack);
void displaystack(t_stack stack);
void deletion(t_stack *stack);
void insert(t_stack *stack, t_stack newnode);
void swap_first_sec(t_stack *stack);
void swap_firsts(t_stack *stack_a, t_stack *stack_b);
void shift_up(t_stack *stack);
void shift_down(t_stack *stack);

#endif
