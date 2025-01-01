/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:43:11 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/01 15:07:04 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	comp(char *oper, char *str)
{
	int	i;

	i = 0;
	while (oper[i] || str[i])
	{
		if (oper[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

void	free_and_exit(char *oper, t_data data, t_link **stack_a,
		t_link **stack_b)
{
	free(oper);
	ft_error("Error\n", data, stack_a, stack_b);
}

void	apply_operation(char *oper, t_data data, t_link **stack_a,
		t_link **stack_b)
{
	if (comp(oper, "sa\n"))
		sa_sb(stack_a, 0);
	else if (comp(oper, "sb\n"))
		sa_sb(stack_b, 0);
	else if (comp(oper, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (comp(oper, "pa\n"))
		pa_pb(stack_b, stack_a, 0);
	else if (comp(oper, "pb\n"))
		pa_pb(stack_a, stack_b, 0);
	else if (comp(oper, "ra\n"))
		ra_rb_rra_rrb(stack_a, 'f', 0);
	else if (comp(oper, "rb\n"))
		ra_rb_rra_rrb(stack_b, 'f', 0);
	else if (comp(oper, "rra\n"))
		ra_rb_rra_rrb(stack_a, 'l', 0);
	else if (comp(oper, "rrb\n"))
		ra_rb_rra_rrb(stack_b, 'l', 0);
	else if (comp(oper, "rr\n"))
		rr_rrr(stack_a, stack_a, 'f', 0);
	else if (comp(oper, "rrr\n"))
		rr_rrr(stack_a, stack_a, 'l', 0);
	else
		free_and_exit(oper, data, stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_link	*stack_a;
	t_link	*stack_b;
	char	*oper;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	data = put_on_it(av, &stack_a, &stack_b);
	data = array_to_stack(&stack_a, &stack_b, data);
	oper = get_next_line(0);
	while (oper)
	{
		apply_operation(oper, data, &stack_a, &stack_b);
		free(oper);
		oper = get_next_line(0);
	}
	if (check_if_sort(stack_a) && (lstsize(stack_b) == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(data, &stack_a, &stack_b);
	exit(0);
}
