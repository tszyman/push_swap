/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:56:17 by tomek             #+#    #+#             */
/*   Updated: 2024/09/12 00:30:04 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_ssplit(char **ssplit)
{
	int	i;

	if (ssplit == NULL)
		return ;
	i = 0;
	while (ssplit[i] != NULL)
	{
		free(ssplit[i]);
		ssplit[i] = NULL;
		i++;
	}
	free(ssplit);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (stack == NULL)
		return ;
	current = stack->head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}
