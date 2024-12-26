/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:53:15 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:36:07 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_stack(t_link **stack,int num_node)
{
    // int	start_sort(t_var data, t_list **stack_a, t_list **stack_b)

	if (num_node == 1)
		return (0);
	else if (num_node == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa_sb(stack, 1);
	}
	else if (num_node == 3)
	{
		// if (!check_if_sort(*stack))
		// 	return (0);
		sort_3(stack);
	}
	// else if (num_node == 4 || num_node == 5)
	// 	sort_4_5(data, stack, stack_b);
	// else
	// {
	// 	full_sort(data, stack, stack_b);
	// 	while (*stack_b)
	// 		last_sort(stack, stack_b, data);
	// }
	return (0);
}

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

