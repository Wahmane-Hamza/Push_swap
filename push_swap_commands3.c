/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:32:47 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 18:33:18 by hwahmane         ###   ########.fr       */
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