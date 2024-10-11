/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:09:32 by tomek             #+#    #+#             */
/*   Updated: 2024/10/11 14:48:04 by tszymans         ###   ########.fr       */
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
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// init
int		*get_and_split(int argc, char **argv, int *size);

//sanity
void	free_ssplit(char **ssplit);
void	free_stack(t_node **stack);

//utils
int		is_nbr(char *s);
long	ft_atol(char *s);

//stack&node
void	init_and_fill(t_node **stack_a, int *split, int size);
void	append_node(t_node **stack, int n);
void	update_index(t_node *stack);
void	set_cheapest(t_node *stack);
t_node	*get_cheapest(t_node *stack);

//stack utils
int		stack_len(t_node *stack);
int		stack_sorted(t_node *stack);
t_node	*find_last(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

//prep_nodes_a
void	prep_nodes_a(t_node *stack_a, t_node *stack_b);
void	move_a_to_b(t_node **stack_a, t_node **stack_b);

//prep_nodes_b
void	prep_nodes_b(t_node *stack_a, t_node *stack_b);
void	move_b_to_a(t_node **stack_a, t_node **stack_b);

//actions
//		swap
void	sa(t_node **stack_a, bool print);
void	sb(t_node **stack_b, bool print);
void	ss(t_node **stack_a, t_node **stack_b, bool print);
//		rotate
void	ra(t_node **stack_a, bool print);
void	rb(t_node **stack_b, bool print);
void	rr(t_node **stack_a, t_node **stack_b, bool print);
//		rev rotate
void	rra(t_node **stack_a, bool print);
void	rrb(t_node **stack_b, bool print);
void	rrr(t_node **stack_a, t_node **stack_b, bool print);
//		push
void	pa(t_node **stack_a, t_node **stack_b, bool print);
void	pb(t_node **stack_b, t_node **stack_a, bool print);
void	prep_for_push_a(t_node **stack, t_node *top_node);
void	prep_for_push_b(t_node **stack, t_node *top_node);

//		algorithms
void	sort_three(t_node **stack_a);
void	sort_stacks_turk(t_node **stack_a, t_node **stack_b);
void	rev_rot_both(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest);

//error
void	throw_error(void);
int		is_sorted(int *split, int size);
int		has_dupl(int *split, int size);
//helper - to be removed
void	print_stack(t_node	*stack);

#endif
