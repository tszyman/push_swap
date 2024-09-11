/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/12 00:56:40 by tomek            ###   ########.fr       */
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
	i = 0;
	while (i < size)
	{
		printf("%d\n", split[i]);
		i++;
	}

	// Pseudo code

	// Check if the arguments are sorted

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

	// TODO:
	// 1. write is_sorted for list (not stack) if sorted: free(split)


	// stack_a = init_and_fill(split, size);
	// if (stack_a == NULL)
	// 	return (free(split), 1);
	// if (has_duplicates(split, size))
	// 	return (free_stack(stack_a), free(split), put_error(), 1);
	// free(split);
	// stack_b = init_stack();
	// if (stack_b == NULL)
	// 	return (free_stack(stack_a), 1);
}
