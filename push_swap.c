/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:20:40 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:34 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"


void createlist(int n,char *arr[], struct node **stack)
{
  struct node *tmp;
  struct node *newnode;
  int i;
  
  i = 2;
  *stack_a = (struct node *)malloc(sizeof(struct node));
  if (!stack_a)
    ft_printf("mem alloc failed");
  (*stack_a)->data = ft_atoi(argv[1]);
  (*stack_a)->next = *stack_a;
  (*stack_a)->prev = *stack_a;
  tmp = *stack_a;
  while (i < argc)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode)
       ft_printf("mem alloc failed");
    newnode->data = ft_atoi(argv[i]);
    newnode->next = *stack_a;
    newnode->prev = tmp;
    tmp->next = newnode;
    (*stack_a)->prev = newnode;
    tmp = tmp->next;
    i++;
  }
 }

void push_swap(int num, char **arr)
{
  createlist(num, arr, stack_a);
}
