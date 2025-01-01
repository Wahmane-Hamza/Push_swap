/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:32:47 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/01 15:02:52 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	bubble_sort(t_data data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < data.y - 1)
	{
		j = 0;
		while (j < data.y - 1)
		{
			if (data.array[j] > data.array[j + 1])
			{
				tmp = data.array[j];
				data.array[j] = data.array[j + 1];
				data.array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (data);
}

void	free_all(t_data data, t_link **stack_a, t_link **stack_b)
{
	int	i;

	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (data.array)
		free(data.array);
	if (data.args)
		free(data.args);
	if (data.split)
	{
		i = 0;
		while (data.split[i])
		{
			free(data.split[i]);
			i++;
		}
		free(data.split);
	}
}
