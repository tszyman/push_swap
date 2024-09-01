/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:09:32 by tomek             #+#    #+#             */
/*   Updated: 2024/09/01 16:36:10 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

// init
t_node	init_node(int data);
t_stack	init_stack(void);

//sanity
int		is_sorted(t_stack *stack);
int		has_dupl(t_stack *stack);
int		is_empty(t_stack *stack);

//utils
int		is_nbr(char *s);
long	ft_atol(const char *s);

//actions

//sort

//error
void	throw_error(void);

#endif