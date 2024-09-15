/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:31:26 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 22:55:49 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*max_node;

	max_node = find_max(*stack_a);
	if (max_node = *stack_a)
		ra(stack_a, true);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, true);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, true);
}
