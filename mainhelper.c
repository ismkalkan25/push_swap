/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainhelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:03:40 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/25 15:41:06 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

void	free_all(t_stack *stack)
{	
	t_node	*tmp;
	t_node	*next_node;

	if (!stack)
		return ;
	tmp = stack->a;
	while (tmp != NULL)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	tmp = stack->b;
	while (tmp != NULL)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	free(stack);
}

int	is_duplicate(t_node *head, int num)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->content == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
		node->content = num;
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
		node->content = num;
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
