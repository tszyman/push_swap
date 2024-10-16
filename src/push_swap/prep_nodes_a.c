/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:21:14 by tomek             #+#    #+#             */
/*   Updated: 2024/10/11 14:46:33 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rot_both(stack_a, stack_b, cheapest);
	prep_for_push_a(stack_a, cheapest);
	prep_for_push_b(stack_b, cheapest->target);
	pb(stack_b, stack_a, true);
}

void	prep_nodes_a(t_node *stack_a, t_node *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
