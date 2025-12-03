/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:01 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/26 16:43:26 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_number(char *str)
{
  int i;

  i = 0;
  if (!str || str[0] == '\0')
    return (0);
  if (str[0] == '-' || str[0] == '+')
    i++;
  while (str[i])
  {
    if (!ft_isdigit((unsigned char)str[i]))
      return (0);
    i++;
  }
  return (1);
}

int stack_sorted(t_stack *stack)
{
  t_node *head;
  t_node *tmp;

  if (!stack || !*stack)
    return (1);
  head = *stack;
  tmp = head->next;
  while (tmp != head)
  {
    if (tmp->prev->data > tmp->data)
      tmp = tmp->next;
    else
      return (0);
  }
  return (1);
}

int stack_size(t_stack stack)
{
  t_node tmp;
  int count = 0;

  if (!stack)
    return 0;
  tmp = stack;
  count++;
  tmp = tmp->next;
  while (tmp != stack)
  {
    count++;
    tmp = tmp->next;
  }
  return (count);
}

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
