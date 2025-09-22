/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:13:57 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/22 13:46:30 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".../libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

t_stack	*initiate_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

int	handle_input(int ac, char **av, t_stack *stack)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	if (ac == 2 && parse_arg(av[1], stack))
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	if (ac > 2 && parse_multiple_arg(stack, ac, av))
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = initiate_stack;
	if (!stack)
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
}
