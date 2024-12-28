/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:51:17 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/28 17:37:57 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_link **stack)
{
	t_link	*first;
	t_link	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
		*stack = second;
		return ;
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = last(*stack);
	second->prev->next = second;
	*stack = second;
}

void	push_a_b(t_link **f_stack, t_link **s_stack)
{
	t_link	*topa;

	topa = *f_stack;
	if (*f_stack != NULL)
	{
		if ((*f_stack)->next != *f_stack)
		{
			*f_stack = (*f_stack)->next;
			(*f_stack)->prev = topa->prev;
			topa->prev->next = *f_stack;
		}
		else
			*f_stack = NULL;
		change_link(s_stack, &topa, 'f');
	}
}

void	fi_lst_or_lst_fi(t_link **stack, char type, int flag)
{
	if (type == 'f')
	{
		*stack = (*stack)->next;
		if (flag == 1)
			write(1, "ra\n", 3);
		else if (flag == 2)
			write(1, "rb\n", 3);
	}
	else if (type == 'l')
	{
		*stack = (*stack)->prev;
		if (flag == 1)
			write(1, "rra\n", 4);
		else if (flag == 2)
			write(1, "rrb\n", 4);
	}
	else
		return ;
}

int	check_if_sort(t_link *stack)
{
	t_link	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_data	array_to_stack(t_link **stack_a, t_data data)
{
	int		i;
	t_link	*new;

	i = 0;
	data.array = malloc(data.y * sizeof(int));
	if (!data.array)
		ft_error("Error : data.array allocation faild");
	while (i < data.y)
	{
		new = ft_lstnew(ft_atoi(data.split[i]));
		change_link(stack_a, &new, 'b');
		data.array[i] = ft_atoi(data.split[i]);
		i++;
	}
	return (data);
}
