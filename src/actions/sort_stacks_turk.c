/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_turk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:12:34 by tomek             #+#    #+#             */
/*   Updated: 2024/09/17 21:18:18 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rr(stack_a, stack_b, true);
	update_index(*stack_a);
	update_index(*stack_b);
}

void	rev_rot_both(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rrr(stack_a, stack_b, true);
	update_index(*stack_a);
	update_index(*stack_b);
}

static void	min_on_top(t_node **stack_a)
{
	while ((*stack_a)->data != find_min(*stack_a)->data)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	sort_stacks_turk(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		prep_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		prep_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	update_index(*stack_a);
	min_on_top(stack_a);
}
