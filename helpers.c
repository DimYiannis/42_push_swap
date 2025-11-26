/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:45:38 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


t_node *deletion(t_stack *stack)
{
  t_node *tmp;
  t_node *last;
 
  if (!stack || !*stack)
    return (NULL);
  tmp = *stack;
  if (tmp->next == tmp)
  {
    *stack = NULL;
    tmp->next = tmp->prev = tmp;
    return tmp;
  }
  last = tmp->prev;

  last->next = tmp->next;
  tmp->next->prev = last;

  *stack = tmp->next;

  tmp->next = tmp->prev = tmp;
  return (tmp);
}

void insert(t_stack *stack, t_node *newnode)
{
  t_node *last;

  if (!stack || !newnode)
    return;
   if (!*stack)
  {
    newnode->next = newnode;
    newnode->prev = newnode;
    *stack = newnode;
    return;
  }
  last = (*stack)->prev;
  newnode->next = *stack;
  newnode->prev = last;
  last->next = newnode;
  (*stack)->prev = newnode;
  *stack = newnode;
}

void displaystack(t_stack stack)
{
    t_node *tmp;

    if (!stack)
        return;
    tmp = stack;
    while (1)
    {
        ft_printf("%d\n", tmp->data);
        tmp = tmp->next;
        if (tmp == stack)
            break;
    }
}

void createlist(int n, char *arr[], t_stack *stack)
{
  t_node *tmp;
  t_node *newnode;
  int i;
  
  i = 1;
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
  i = 2;
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
