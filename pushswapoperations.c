/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapoperations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:29:38 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 15:20:40 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	sa(t_node **a, int check)
{
	int	tmp_val;
	int	tmp_idx;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp_val = (*a)->content;
	tmp_idx = (*a)->index;
	(*a)->content = (*a)->next->content;
	(*a)->index = (*a)->next->index;
	(*a)->next->content = tmp_val;
	(*a)->next->index = tmp_idx;
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int check)
{
	int	tmp_val;
	int	tmp_idx;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp_val = (*b)->content;
	tmp_idx = (*b)->index;
	(*b)->content = (*b)->next->content;
	(*b)->index = (*b)->next->index;
	(*b)->next->content = tmp_val;
	(*b)->next->index = tmp_idx;
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	int	check;

	check = 1;
	sa(a, check);
	sb(b, check);
	write(1, "ss\n", 3);
}
