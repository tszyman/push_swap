/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:09:32 by tomek             #+#    #+#             */
/*   Updated: 2024/09/12 00:06:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

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
int		*get_and_split(int argc, char **argv, int *size);
int		*split_arg(char *arg, int *size);
int		get_ssize(char **ssplit);

//sanity
int		is_sorted(t_stack *stack);
int		has_dupl(int *split, int size);
int		is_empty(t_stack *stack);
void	free_ssplit(char **ssplit);
void	free_stack(t_stack *stack);

//utils
int		is_nbr(char *s);
long	ft_atol(char *s);

//stack&node
void	add_back(t_stack *stack, t_node *node);
t_node	*init_node(int data);
t_stack	*init_stack(void);
t_stack	*init_and_fill(int *split, int size);

//actions

//sort

//error
void	throw_error(void);

#endif