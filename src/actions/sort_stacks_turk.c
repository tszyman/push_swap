/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_turk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:12:34 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 21:46:00 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rr(stack_a, stack_b, true);
	update_index(*stack_a);
	update_index(*stack_b);
}

static void	rev_rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, true);
	update_index(*stack_a);
	update_index(*stack_b);
}

static void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'stack_a');
	prep_for_push(stack_b, cheapest_node->target, 'stack_b');
	pb(stack_b, stack_a, true);
}

static void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'stack_a');
	pa(stack_a, stack_b, true);
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
