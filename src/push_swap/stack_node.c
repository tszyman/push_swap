/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:30:00 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 01:25:07 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_and_fill(t_node **stack_a, int *split, int size)
{
	int		i;
	
	i = 0;
	while (i < size)
	{
		append_node(stack_a, split[i]);
		i++;
	}
}

void	print_stack(t_node	*stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}
