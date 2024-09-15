/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:21:14 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 01:09:19 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*curr_b;
	t_node	*target;
	long	close_small_nbr;

	while (stack_a)
	{
		close_small_nbr = LONG_MIN;
		curr_b = stack_b;
		while (curr_b)
		{
			if (curr_b->data < stack_a->data && curr_b->data > close_small_nbr)
			{
				close_small_nbr = curr_b->data;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (close_small_nbr == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;
	
	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prep_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}