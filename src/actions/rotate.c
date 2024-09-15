/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:00:27 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 23:33:23 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last_node;
	
	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **stack_a, bool print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **stack_b, bool print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}