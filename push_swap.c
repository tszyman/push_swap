/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/02 21:58:28 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*split;
	int			size;
	int			i;
//	t_stack		*stack_a;
//	t_stack		*stack_b;

	split = get_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	i = 0;
	printf("Size: %d\n", size);
	while (i < size)
	{
		printf("%d\n", split[i]);
		i++;
	}
	if (has_dupl(split, size))
		return (free(split), throw_error(), 1);
	// stack_a = init_and_fill(split, size);
	// if (stack_a == NULL)
	// 	return (free(split), 1);
	// free(split);
	// stack_b = init_stack();
	// if (stack_b == NULL)
	// 	return (free_stack(stack_a), 1);
}
