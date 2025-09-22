/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:16:44 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/22 13:48:29 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				content;
	int				next;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	a;
	t_node	b;
}	t_stack;

int		is_duplicate(t_node *head, int num);
void	clear_stack(t_node	**head);
int		parse_arg(char *box, t_stack *stack);
int		parse_multiple_arg(t_stack *stack, int ac, char **av);
void	add_node_end(t_node **head, t_node *new_node);
void	rrb(t_node **b);
void	rra(t_node **a);
void	rb(t_node **b);
void	ra(t_node **a);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

#endif