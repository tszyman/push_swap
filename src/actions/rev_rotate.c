/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:00:27 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 23:34:06 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last_node;
	
	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}