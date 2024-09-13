/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:51:55 by tomek             #+#    #+#             */
/*   Updated: 2024/09/13 23:22:06 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_ssize(char **ssplit)
{
	int	count;

	count = 0;
	if (ssplit == NULL)
		return (0);
	while (*ssplit != NULL)
	{
		count++;
		ssplit++;
	}
	return (count);
}

int	*split_arg(char *arg, int *size)
{
	char	**ssplit;
	int		*split;
	int		i;

	ssplit = ft_split(arg, ' ');
	if (ssplit == NULL)
		return (NULL);
	*size = get_ssize(ssplit);
	split = (int *)malloc(*size * sizeof(int));
	if (split == NULL)
		return (free_ssplit(ssplit), NULL);
	i = 0;
	while (ssplit[i] != NULL)
	{
		if (!is_nbr(ssplit[i]) || ft_atol(ssplit[i]) < INT_MIN
			|| ft_atol(ssplit[i]) > INT_MAX)
			return (free(split), free_ssplit(ssplit), throw_error(), NULL);
		split[i] = ft_atoi(ssplit[i]);
		i++;
	}
	free_ssplit(ssplit);
	return (split);
}

int	*get_and_split(int argc, char **argv, int *size)
{
	int		*split;
	int		i;

	if (argc == 1)
		return (*size = 0, NULL);
	if (argc == 2)
		return (split_arg(argv[1], size));
	else
	{
		*size = argc - 1;
		split = (int *)malloc(*size * sizeof(int));
		if (split == NULL)
			return (NULL);
		i = argc - 1;
		while (i > 0)
		{
			if (!is_nbr(argv[i]) || ft_atol(argv[i]) < INT_MIN
				|| ft_atol(argv[i]) > INT_MAX)
				return (free(split), throw_error(), NULL);
			split[i - 1] = ft_atoi(argv[i]);
			i--;
		}
	}
	return (split);
}
