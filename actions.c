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
  tmp = *stack;

  if (stack==NULL || *stack == NULL)
    return;
  (*stack) = (*stack)->next;
  free(tmp);
}

void insert(struct node **stack, struct node newnode)
{
  
}
