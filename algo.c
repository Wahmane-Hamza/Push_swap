/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:53:15 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:54:52 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_link **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{
		ra_rb_rra_rrb(stack_a, 'l');
		sa_sb(stack_a, 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		sa_sb(stack_a, 1);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		ra_rb_rra_rrb(stack_a, 'l');
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ra_rb_rra_rrb(stack_a, 'f');
		sa_sb(stack_a, 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->next->content)
		ra_rb_rra_rrb(stack_a, 'f');
	return ;
}

int sort_stack(t_data data, t_link **stack_a, t_link **stack_b)
{
    if (data.y == 1)
		return (0);
	else if (data.y == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a, 1);
	}
	else if (data.y == 3)
	{
		if (!check_if_sort(*stack_a))
			return (0);
		sort_3(stack_a);
	}
	// else if (data.y == 4 || data.y == 5)
	// 	sort_4_5(data, stack_a, stack_b);
	// else
	// {
	// 	full_sort(data, stack_a, stack_b);
	// 	while (*stack_b)
	// 		last_sort(stack_a, stack_b, data);
	// }
	return (0);
}