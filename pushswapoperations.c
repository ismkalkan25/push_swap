/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:29:38 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/11 13:02:44 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*b == NULL)
		*b = temp;
	else
	{
		temp->next = *b;
		*b = temp;
	}
}

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*a == NULL)
		*a = temp;
	else
	{
		temp->next = *a;
		*a = temp;
	}
}

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if ((*a == NULL) || (*a->next == NULL))
		return ;
	first = *a;
	second = *a->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if ((*b == NULL) || (*b->next == NULL))
		return ;
	first = *b;
	second = *b->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
