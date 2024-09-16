/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:00:27 by tomek             #+#    #+#             */
/*   Updated: 2024/09/16 21:56:53 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*push_node;
	
	if(!src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);
	if(print)
		ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a, bool print)
{
	push(stack_b, stack_a);
	if(print)
		ft_printf("pb\n");
}

void	prep_for_push_a(t_node **stack, t_node *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			ra(stack, true);
		else
			rra(stack, true);
	}
}

void	prep_for_push_b(t_node **stack, t_node *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			rb(stack, true);
		else
			rrb(stack, true);
	}
}