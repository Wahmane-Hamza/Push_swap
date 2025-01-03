/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/29 18:38:34 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_link **stack, int flag)
{
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
	swap(stack);
}

void	ss(t_link **stack_a, t_link **stack_b, int flag)
{
	if (flag == 1)
		write(1, "ss\n", 3);
	swap(stack_a);
	swap(stack_b);
}

void	pa_pb(t_link **first, t_link **second, int flag)
{
	if (flag == 1)
		write(1, "pa\n", 3);
	else if (flag == 2)
		write(1, "pb\n", 3);
	push_a_b(first, second);
}

void	ra_rb_rra_rrb(t_link **stack, char type, int flag)
{
	fi_lst_or_lst_fi(stack, type, flag);
}

void	rr_rrr(t_link **stack_a, t_link **stack_b, char type, int flag)
{
	fi_lst_or_lst_fi(stack_a, type, 0);
	fi_lst_or_lst_fi(stack_b, type, 0);
	if (type == 'f' && flag == 1)
		write(1, "rr\n", 3);
	else if (type == 'l' && flag == 1)
		write(1, "rrr\n", 3);
}
