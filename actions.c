/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/16 20:21:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void deletion(struct node **stack)
{
  struct node *tmp;
  struct node *tranverse;
  
  tmp = *stack;
  tranverse = (*stack)->next;
  if (stack==NULL || *stack == NULL)
    return;
  while (tranverse->next != *stack)
    tranverse = tranverse->next;
  tranverse->next = (*stack)->next;
  (*stack) = (*stack)->next;
  (*stack)->prev = tranverse;
  free(tmp);
}

void insert(struct node **stack, struct node *newnode)
{

  if (*stack == NULL)
    *stack = newnode;
  newnode->next = *stack;
  newnode->prev = (*stack)->prev;
  (*stack)->prev = newnode;
  *stack = newnode;
}
