/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:25:19 by ydimitra          #+#    #+#             */
/*   Updated: 2025/12/07 21:20:42 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*deletion(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack)
		return (NULL);
	tmp = *stack;
	if (tmp->next == tmp)
	{
		*stack = NULL;
		tmp->next = tmp;
		tmp->prev = tmp;
		return (tmp);
	}
	last = tmp->prev;
	last->next = tmp->next;
	tmp->next->prev = last;
	*stack = tmp->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	insert(t_stack *stack, t_node *newnode)
{
	t_node	*last;

	if (!stack || !newnode)
		return ;
	if (!*stack)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*stack = newnode;
		return ;
	}
	last = (*stack)->prev;
	newnode->next = *stack;
	newnode->prev = last;
	last->next = newnode;
	(*stack)->prev = newnode;
	*stack = newnode;
}

void	displaystack(t_stack stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (1)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}

static long check_overflow(char *str, int sign, int *overflow)
{
  long num;
  int digit;
  int min_last_digit = (int)(-(long)INT_MIN % 10);

  num = 0;
  while (ft_isnum(*str))
  {
    digit = *str - '0';
    if (num > INT_MAX / 10)
      return (*overflow = 1, 0);
    if (num == INT_MAX / 10)
    {
      if (sign == 1 && digit > INT_MAX % 10)
        return (*overflow = 1, 0);
      if (sign == -1 && digit > min_last_digit)
        return (*overflow = 1, 0);
    }
    num = num * 10 + digit;
    str++;
  }
  return (num);
}

long	ft_atol(char *str, int *overflow)
{
	int		sign;
	long	num;
  int counter;

  counter = 0;
  *overflow = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1; 
		str++;
    counter++;
	}
  if (counter > 1)
    return (*overflow = 1, 0);
  check_overflow(str, sign, overflow);
  if (*overflow == 1)
    return (0);
	return (num * sign);
}

