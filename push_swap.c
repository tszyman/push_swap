/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:02:11 by tomek             #+#    #+#             */
/*   Updated: 2024/09/01 19:21:47 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*split;
	int			size;
	t_stack		*stack_a;
	t_stack		*stack_b;

	split = get_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	stack_a = init_and_fill(split, size);
	if (stack_a == NULL)
		return (free(split), 1);
	if (has_duplicates(split, size))
		return (free_stack(stack_a), free(split), put_error(), 1);
	free(split);
	stack_b = init_stack();
	if (stack_b == NULL)
		return (free_stack(stack_a), 1);
}
