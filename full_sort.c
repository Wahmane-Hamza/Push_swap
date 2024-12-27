/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:03:05 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 18:05:23 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	find_max(t_link *stack)
{
	int		i;
	t_data	data;
    t_link  *start;

	i = 0;
	data.mpos = 0;
	data.max = (stack)->content;
    start = stack;
	if (lstsize(stack) >= 2)
	{
		while (stack->next != start)
		{
			if (data.max < (stack)->next->content)
			{
				data.max = (stack)->next->content;
				data.mpos = i + 1;
			}
			i++;
			stack = (stack)->next;
		}
	}
	return (data);
}

int	lstsize(t_link *lst)
{
	int	i;
    t_link *list_break;

	i = 0;
    list_break = lst;
	while (list_break != lst->next)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

void	last_sort(t_link **stack_a, t_link **stack_b, t_data data)
{
    // printf("max %d\n",data.max);
	data = find_max(*stack_b);
	if (data.mpos <= (lstsize(*stack_b) / 2))
	{
		while (data.max != (*stack_b)->content)
			ra_rb_rra_rrb(stack_b, 'f', 2);

	}
	else
		while (data.max != (*stack_b)->content)
			ra_rb_rra_rrb(stack_b, 'l', 2);
	pa_pb(stack_b, stack_a, 1);
}

int	get_rang(t_data data)
{
	if (data.y <= 16)
		return (3);
	if (data.y <= 100)
		return (13);
	if (data.y <= 500)
		return (30);
	if (data.y > 500)
		return (45);
	return (0);
}

void	check_swap(t_link **stack)
{
	if (lstsize(*stack) >= 2)
	{
		if ((*stack)->content < (*stack)->next->content)
			sa_sb(stack, 2);
	}
}