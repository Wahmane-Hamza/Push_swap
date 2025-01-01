/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/30 16:38:44 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_link	*stack_a;
	t_link	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	data = put_on_it(av, &stack_a, &stack_a);
	data = array_to_stack(&stack_a, &stack_b, data);
	if (check_if_sort(stack_a))
	{
		free_stack(&stack_a);
		free(data.array);
		return (0);
	}
	data = bubble_sort(data);
	sort_stack(data, &stack_a, &stack_b);
	free_all(data, &stack_a, &stack_b);
	exit(0);
}
