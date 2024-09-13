/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/13 23:38:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*split;
	int			size;
//	t_stack		*stack_a;
//	t_stack		*stack_b;
	int			i;

	split = get_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	if (has_dupl(split, size))
		exit (0);
	
	i = 0;
	while (i < size)
	{
		printf("%d\n", split[i]);
		i++;
	}
	if (!is_sorted(split, size))
	{
		printf("The list is not yet sorted!\n");
	
	// Pseudo code
	// If list not sorted
		// Init stack
		
		// If stack len == 2
			// Swap numbers
		// Else if stack len == 3
			// call sort_three algorithm
		// Else (stack > 3 elements)
			// call Turk algorithm
		
		// Clean the stack
	// END

	}
	else 
	{
		printf("The list is already sorted!\n");
	}

	// TODO:
	// 1 Init stack (stack printing helper function)
	// 2 Implement atomic functions
	// 3 Implement stack cleaning
	// 4 Implement for 2 element stack
	// 5 implement sort three algorithm
	// 6 Implement Turk algorithm

	// stack_a = init_and_fill(split, size);
	// if (stack_a == NULL)
	// 	return (free(split), 1);
	// free(split);
	// stack_b = init_stack();
	// if (stack_b == NULL)
	// 	return (free_stack(stack_a), 1);
}
