/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:30:07 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 18:29:06 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bit_calc(t_node **a, t_node **b, int bit)
{
	int	i;
	int	size;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
		size = stack_size(*a);
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		bit_calc(a, b, i);
		while (*b)
			pa(a, b);
		i++;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && first < third)
		sa(a, 0);
	else if ((first > second) & (second > third))
	{
		sa(a, 0);
		rra(a);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(a);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(a, 0);
		ra(a);
	}
	else
		rra(a);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (*b && (*b)->index < (*b)->next->index)
		sb(b, 0);
	while (*b)
		pa(a, b);
}
