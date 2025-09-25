/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rroperations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:04:38 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 12:42:09 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if ((*a == NULL) || ((*a)->next == NULL))
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if ((*b == NULL) || ((*b)->next == NULL))
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write (1, "rb\n", 3);
}

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*before_last;

	if ((*a == NULL) || ((*a)->next == NULL))
		return ;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	write (1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*before_last;

	if ((*b == NULL) || ((*b)->next == NULL))
		return ;
	before_last = *b;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	write (1, "rrb\n", 4);
}

void	give_index(t_node *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->content < current->content)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}
