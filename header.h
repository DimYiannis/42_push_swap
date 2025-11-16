/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:16:02 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/16 19:21:29 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H
# include "printf/libft/libft.h"
# include "printf/ft_printf_bonus.h"

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} *stack_a, *stack_b;



#endif
