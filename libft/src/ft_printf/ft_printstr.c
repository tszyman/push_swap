/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:30:00 by tomek             #+#    #+#             */
/*   Updated: 2024/09/11 23:47:01 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	add_back(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = NULL;
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->size++;
}