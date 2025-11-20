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

void	free_up(t_node *head)
{
  t_node *node;
  t_node *tmp;

  if (!head)
    return;
  node = head->next;
  head->prev->next = NULL;
	while (node)
  {
    tmp = node->next;
    free(node);
    node = tmp;
  }
  free(head);
}

void createlist(int n, char *arr[], t_stack *stack)
{
  t_node *tmp;
  t_node *newnode;
  int i;
  
  i = 2;
  if (n < 2)
  {
    ft_printf("Error\n");
    *stack = NULL;
    return;
  }
   if(!arr[i] || !is_number(arr[i]))
    {
      ft_printf("Error\n");
      free_up(*stack);
      *stack = NULL;
      return;
    }
  *stack = malloc(sizeof(t_node));
  if (!(*stack))
  {
    ft_printf("Error\n");
    *stack = NULL;
    return;
  }
  (*stack)->data = ft_atoi(arr[1]);
  (*stack)->next = *stack;
  (*stack)->prev = *stack;
  tmp = *stack;
  while (i < n)
  {
    if(!arr[i] || !is_number(arr[i]))
    {
      ft_printf("Error\n");
      free_up(*stack);
      *stack = NULL;
      return;
    }
    newnode = malloc(sizeof(t_node));
    if (!newnode)
    {
      ft_printf("Error\n");
      free_up(*stack);
      *stack = NULL;
      return;
    }
    newnode->data = ft_atoi(arr[i]);
    newnode->next = *stack;
    newnode->prev = tmp;
    tmp->next = newnode;
    (*stack)->prev = newnode;
    tmp = newnode;
    i++;
  }
 }

void displaystack(t_stack stack)
{
    t_node *tmp;
    
  if (!stack)
    return;
  tmp = stack;
    ft_printf("%d\n", tmp->data);
    tmp = tmp->next;
    while (tmp != stack)
    {
        ft_printf("\n%d", tmp->data);
        tmp = tmp->next;
    }
}

// void push_swap(t_stack **stack_a, t_stack **stack_b)
// {
//
//
// }
