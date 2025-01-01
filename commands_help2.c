/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:21:48 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/01 15:01:11 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str, t_data data, t_link **stack_a, t_link **stack_b)
{
	write(2, str, ft_strlen(str));
	free_all(data, stack_a, stack_b);
	exit(1);
}

t_data	put_on_it(char **av, t_link **stack_a, t_link **stack_b)
{
	t_data	data;
	int		i;

	data.args = NULL;
	data.split = NULL;
	data.array = NULL;
	data.y = 0;
	i = 1;
	while (av[i])
	{
		data.args = ft_strjoin(av[i], data, stack_a, stack_b);
		i++;
	}
	data.split = ft_split(data.args, ' ');
	data = check_all(data, stack_a, stack_a);
	i = 0;
	free(data.args);
	data.args = NULL;
	return (data);
}

t_data	check_all(t_data data, t_link **stack_a, t_link **stack_b)
{
	long	x;
	long	i;

	i = 0;
	data.y = 0;
	while (data.split[data.y])
	{
		x = ft_atoi(data.split[data.y], data, stack_a, stack_b);
		i = data.y;
		while (data.split[i])
		{
			if (data.split[i + 1] == NULL)
				break ;
			if (x == ft_atoi(data.split[i + 1], data, stack_a, stack_b))
				ft_error("Error\n", data, stack_a, stack_b);
			i++;
		}
		data.y++;
	}
	return (data);
}

int	get_min_pos(t_link *stack)
{
	int		i;
	int		j;
	int		value;
	t_link	*current;

	i = 0;
	j = 0;
	value = stack->content;
	current = stack;
	while (current->next != stack)
	{
		if (value > current->next->content)
		{
			value = current->next->content;
			j = i + 1;
		}
		current = current->next;
		i++;
	}
	return (j);
}

void	free_stack(t_link **stack)
{
	t_link	*current;
	t_link	*next_node;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (1)
	{
		next_node = current->next;
		free(current);
		if (next_node == *stack)
			break ;
		current = next_node;
	}
	*stack = NULL;
}
