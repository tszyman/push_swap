/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/17 21:07:42 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*split;
	int			size;
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	split = get_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	if (has_dupl(split, size))
		exit (0);
	if (!is_sorted(split, size))
	{
		init_and_fill(&stack_a, split, size);
		free(split);
		if (stack_len(stack_a) == 2)
			sa(&stack_a, true);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks_turk(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
