/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:36:22 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 01:25:09 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	stack_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	long	max_val;

	if (!stack)
		return (0);
	max_val = LONG_MIN;
	while (stack)
	{
		if (stack->data > max_val)
		{
			max_val = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
