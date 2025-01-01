/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:53:15 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/01 15:01:29 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_link **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{
		ra_rb_rra_rrb(stack_a, 'l', 1);
		sa_sb(stack_a, 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		sa_sb(stack_a, 1);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		ra_rb_rra_rrb(stack_a, 'l', 1);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ra_rb_rra_rrb(stack_a, 'f', 1);
		sa_sb(stack_a, 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->next->content)
		ra_rb_rra_rrb(stack_a, 'f', 1);
	return ;
}

void	push_min(t_link **stack_a, t_link **stack_b)
{
	int	x;

	x = get_min_pos(*stack_a);
	while (get_min_pos(*stack_a) != 0 && x >= 3)
		ra_rb_rra_rrb(stack_a, 'l', 1);
	while (get_min_pos(*stack_a) != 0)
		ra_rb_rra_rrb(stack_a, 'f', 1);
	if (get_min_pos(*stack_a) == 0)
		pa_pb(stack_a, stack_b, 2);
}

void	sort_4_5(t_data data, t_link **stack_a, t_link **stack_b)
{
	if (data.y == 5)
		push_min(stack_a, stack_b);
	push_min(stack_a, stack_b);
	sort_3(stack_a);
	if (data.y == 5)
		pa_pb(stack_b, stack_a, 1);
	pa_pb(stack_b, stack_a, 1);
}

void	full_sort(t_data data, t_link **stack_a, t_link **stack_b)
{
	int	r;
	int	i;

	i = 0;
	r = get_rang(data);
	while (*stack_a)
	{
		if (r + i >= data.y)
			r = data.y - i - 1;
		if ((*stack_a)->content >= data.array[i]
			&& (*stack_a)->content <= data.array[r + i])
		{
			pa_pb(stack_a, stack_b, 2);
			check_swap(stack_b);
			i++;
		}
		else if ((*stack_a)->content < data.array[i])
		{
			pa_pb(stack_a, stack_b, 2);
			ra_rb_rra_rrb(stack_b, 'f', 2);
			i++;
		}
		else
			check_revers(stack_a);
	}
}

int	sort_stack(t_data data, t_link **stack_a, t_link **stack_b)
{
	if (data.y == 1)
		return (0);
	else if (data.y == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa_sb(stack_a, 1);
	}
	else if (data.y == 3)
	{
		if (check_if_sort(*stack_a))
			return (0);
		sort_3(stack_a);
	}
	else if (data.y == 4 || data.y == 5)
		sort_4_5(data, stack_a, stack_b);
	else
	{
		full_sort(data, stack_a, stack_b);
		while (*stack_b)
			last_sort(stack_a, stack_b, data);
	}
	return (0);
}
