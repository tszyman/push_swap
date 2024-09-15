/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:00:27 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 22:27:12 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return (0);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node **stack_a, bool print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **stack_b, bool print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}