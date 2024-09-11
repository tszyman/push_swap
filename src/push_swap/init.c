/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:51:55 by tomek             #+#    #+#             */
/*   Updated: 2024/09/11 23:49:04 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->size = 0;
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

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
		if (!is_nbr(ssplit[i]) || ft_atol(ssplit[i]) < -2147483648
			|| ft_atol(ssplit[i]) > 2147483647)
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
			if (!is_nbr(argv[i]) || ft_atol(argv[i]) < -2147483648
				|| ft_atol(argv[i]) > 2147483647)
				return (free(split), throw_error(), NULL);
			split[i - 1] = ft_atoi(argv[i]);
			i--;
		}
	}
	return (split);
}

t_stack	*init_and_fill(int *split, int size)
{
	t_stack	*stack_a;
	t_node	*tmp;
	int		i;

	stack_a = init_stack();
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp = init_node(split[i]);
		if (tmp == NULL)
			return (free_stack(stack_a), NULL);
		add_back(stack_a, tmp);
		i++;
	}
	return (stack_a);
}

t_node	*init_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
