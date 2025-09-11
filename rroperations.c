/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rroperations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:04:38 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/11 16:02:44 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if ((*a == NULL) || (*a->next == NULL))
		return ;
	first = *a;
	*a = *a->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if ((*b == NULL) || (*b->next == NULL))
		return ;
	first = *b;
	*b = *b->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*before_last;

	if ((*a == NULL) || (*a->next == NULL))
		return ;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*before_last;

	if ((*b == NULL) || (*b->next == NULL))
		return ;
	before_last = *b;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
}

int	is_duplicate(t_node *head, int num)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
