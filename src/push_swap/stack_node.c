/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:30:00 by tomek             #+#    #+#             */
/*   Updated: 2024/09/12 00:33:22 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

t_stack	*init_and_fill(int *split, int size)
{
	t_stack	*stack_a;
	t_node	*tmp;
	int		i;

	stack_a = init_stack();
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp = init_node(split[i]);
		if (tmp == NULL)
			return (free_stack(stack_a), NULL);
		add_back(stack_a, tmp);
		i++;
	}
	return (stack_a);
}

t_node	*init_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->size = 0;
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}