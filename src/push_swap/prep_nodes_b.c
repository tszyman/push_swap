/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:21:14 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 21:46:26 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*curr_a;
	t_node	*target;
	long	close_big_nbr;
	
	while (stack_b)
	{
		close_big_nbr = LONG_MAX;
		curr_a = stack_a;
		while (curr_a)
		{
			if (curr_a->data > stack_b->data && curr_a->data < close_big_nbr)
			{
				close_big_nbr = curr_a->data;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (close_big_nbr == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
	stack_b = stack_b->next;
	}
}

void	prep_nodes_b(t_node *stack_a, t_node *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	set_target_b(stack_a, stack_b);
}