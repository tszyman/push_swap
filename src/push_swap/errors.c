/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:53 by tomek             #+#    #+#             */
/*   Updated: 2024/09/13 23:23:16 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	throw_error(void)
{
	ft_putendl_fd("Error", 2);
}

int	has_dupl(int *split, int size)
{
	int	i;
	int	j;

	if (split == NULL || size <= 1)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (split[i] == split[j])
				return (free(split), throw_error(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *split, int size)
{
	int	amax;
	int	i;

	i = 0;
	amax = INT_MIN;
	while (i < size)
	{
		if (split[i] < amax)
			return (0);
		amax = split[i];
		i++;
	}
	return (free(split), 1);
}
