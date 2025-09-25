/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:13:57 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 18:33:39 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

t_stack	*initiate_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	handle_input(int ac, char **av, t_stack *stack)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (ac == 2 && parse_arg(av[1], stack))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (ac > 2 && parse_multiple_arg(stack, ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = initiate_stack();
	if (!stack || handle_input(ac, av, stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(stack);
		return (1);
	}
	give_index(stack->a);
	if (!is_sorted(stack->a))
	{
		if (stack_size(stack->a) == 2)
			sa(&stack->a, 0);
		else if (stack_size(stack->a) == 3)
			sort_three(&stack->a);
		else if (stack_size(stack->a) <= 5)
			sort_five(&stack->a, &stack->b);
		else
			radix_sort(&stack->a, &stack->b);
	}
	free_all(stack);
	return (0);
}
