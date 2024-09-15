/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_turk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:12:34 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 01:14:44 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
static void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	
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
}
