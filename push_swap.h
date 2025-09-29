/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:16:44 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 16:05:25 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

int		is_duplicate(t_node *head, int num);
void	bit_calc(t_node **a, t_node **b, int bit);
void	radix_sort(t_node **a, t_node **b);
long	ft_atoir(const char *nptr);
int		is_sorted(t_node *stack);
int		handle_num(t_stack *stack, long num);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
int		stack_size(t_node *stack);
void	free_all(t_stack	*stack);
void	free_split_from(char **split, int start);
int		parse_arg(char *box, t_stack *stack);
int		parse_multiple_arg(t_stack *stack, int ac, char **av);
void	add_node_end(t_node **head, t_node *new_node);
void	give_index(t_node *stack);
void	rrb(t_node **b);
void	rra(t_node **a);
void	rb(t_node **b);
void	ra(t_node **a);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	sa(t_node **a, int check);
void	sb(t_node **b, int check);
void	ss(t_node **a, t_node **b);

#endif