/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 23:31:48 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*split;
	int			size;
	t_node		*stack_a;

	stack_a = NULL;
	split = get_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	if (has_dupl(split, size))
		exit (0);
	if (!is_sorted(split, size))
	{
		init_and_fill(&stack_a, split, size);
		free(split);
		print_stack(stack_a);
		if (stack_len(stack_a) == 2)
			sa(&stack_a, true);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			printf("Turk will be played\n");
	
	// Pseudo code
	// If list not sorted
		// Init stack: create stack and append node
		
		// If stack len == 2
			// Swap numbers
		// Else if stack len == 3
			// call sort_three algorithm
		// Else (stack > 3 elements)
			// call Turk algorithm
		
		// Clean the stack
	// END

	}
	free_stack(&stack_a);
	return (0);
	// TODO:
	// 1 Init stack (stack printing helper function)
	// 2 Implement atomic functions
	// 3 Implement stack cleaning
	// 4 Implement for 2 element stack
	// 5 implement sort three algorithm
	// 6 Implement Turk algorithm
}
