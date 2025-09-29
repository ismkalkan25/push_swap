#include "push_swap.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atoir(const char *nptr)
{
	int				i;
	int				sign;
	long			res;

	i = 0;
	sign = 1;
	res = 0;
    if (!is_valid_number(nptr))
		return ((long)INT_MAX + 1);
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i++] - '0');
	}
	return ((res * sign));
}

void	free_split_from(char **split, int start)
{
	int	i;

	i = start;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	handle_num(t_stack *stack, long num)
{
	t_node	*node;

	if (num > INT_MAX || num < INT_MIN || is_duplicate(stack->a, (int)num))
		return (1);
	node = malloc(sizeof(t_node));
	if (!node)
		return (1);
	node->content = (int)num;
	node->next = NULL;
	add_node_end(&stack->a, node);
	return (0);
}
