/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:13:57 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/11 16:13:41 by ikalkan          ###   ########.fr       */
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

int	parse_arg(char *box, t_stack *stack)
{
	char	**new_box;
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	new_box = ft_split(box, ' ');
	if (!new_box)
		return (1);
	while (new_box[i] != NULL)
	{
		num = ft_atoi(new_box[i]);
		if (is_duplicate(stack->a, num))
			return (1);
		node = malloc(sizeof(t_node));
		if (!node)
			return (1);
		node->value = num;
		node->next = NULL;
		add_node_end(&stack->a, node);
		free(new_box[i]);
		i++;
	}
	free(new_box);
	return (0);
}

int	parse_multiple_arg(t_stack *stack, int ac, char **av)
{
	int		i;
	int		num;
	t_node	*node;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (is_duplicate(stack->a, num))
			return (1);
		node = malloc(sizeof(t_node));
		if (!node)
			return (1);
		node->value = num;
		node->next = NULL;
		add_node_end(&stack->a, node);
		i++;
	}
	return (0);
}

void	add_node_end(t_node **head, t_node *new_node)
{
	t_node	*tmp;

	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}




