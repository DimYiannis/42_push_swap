/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:20:40 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/18 15:48:41 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"


void createlist(int n, char *arr[], t_stack *stack)
{
  t_node *tmp;
  t_node *newnode;
  int i;
  
  i = 2;
  *stack = malloc(sizeof(t_stack));
  if (!(*stack))
    ft_printf("Error\n");
  (*stack)->data = ft_atoi(arr[1]);
  (*stack)->next = *stack;
  (*stack)->prev = *stack;
  tmp = *stack;
  while (i < n)
  {
    newnode = malloc(sizeof(t_node));
    if (!newnode)
       ft_printf("Error\n");
    newnode->data = ft_atoi(arr[i]);
    newnode->next = *stack;
    newnode->prev = tmp;
    tmp->next = newnode;
    (*stack)->prev = newnode;
    tmp = tmp->next;
    i++;
  }
 }

void displaystack(t_stack stack)
{
    t_node *tmp;
    
  if (!stack)
    return;
  tmp = stack;
    ft_printf("\n%d", tmp->data);
    tmp = tmp->next;
    while (tmp != stack)
    {
        ft_printf("\n%d", tmp->data);
        tmp = tmp->next;
    }

}

void push_swap(struct node **stack_a, struct node **stack_b)
{


}
