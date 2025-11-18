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
  struct node *next;
  struct node *prev;
} t_node;

typede t_node *t_stack;

void push_swap(struct node **stack_a, struct node **stack_b);
void createlist(int n,char *arr[], struct node **stack);
void displaystack(struct node **stack);
void deletion(struct node **stack);
void insert(struct node **stack, struct node *newnode);
void swap_first_sec(struct node **stack);
void swap_firsts(struct node **stack_a, struct node **stack_b);
void shift_up(struct node **stack);
void shift_down(struct node **stack);

#endif
