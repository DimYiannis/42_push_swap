/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:16:02 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/16 16:30:43 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_Hi
# include "libft/libft.h"

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} *stack_a = NULL, *stack_b = NULL;



#endif
