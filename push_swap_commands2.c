/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:51:17 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 14:04:20 by hwahmane         ###   ########.fr       */
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