/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_Turk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:12:34 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 00:20:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stacks_Turk(t_node **stack_a, t_node **stack_b)
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
		
	}
	
}