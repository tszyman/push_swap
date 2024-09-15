/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:09:32 by tomek             #+#    #+#             */
/*   Updated: 2024/09/15 23:28:08 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// init
int		*get_and_split(int argc, char **argv, int *size);
//int		*split_arg(char *arg, int *size);
//int		get_ssize(char **ssplit);

//sanity
int		is_empty(t_node *stack);
void	free_ssplit(char **ssplit);
void	free_stack(t_node **stack);

//utils
int		is_nbr(char *s);
long	ft_atol(char *s);

//stack&node
void	init_and_fill(t_node **stack_a, int *split, int size);
void	append_node(t_node **stack, int n);

//stack utils
int		stack_len(t_node *stack);
int		stack_sorted(t_node *stack);
t_node	*find_last(t_node *stack);
t_node	*find_max(t_node *stack);

//actions
void	sa(t_node **stack_a, bool print);
void	sb(t_node **stack_b, bool print);
void	ss(t_node **stack_a, t_node **stack_b, bool print);
void	ra(t_node **stack_a, bool print);
void	rb(t_node **stack_b, bool print);
void	rr(t_node **stack_a, t_node **stack_b, bool print);
void	rra(t_node **stack_a, bool print);
void	rrb(t_node **stack_b, bool print);
void	rrr(t_node **stack_a, t_node **stack_b, bool print);
void	sort_three(t_node **stack_a);

//sort

//error
void	throw_error(void);
int		is_sorted(int *split, int size);
int		has_dupl(int *split, int size);

//helper - to be removed
void	print_stack(t_node	*stack);

#endif