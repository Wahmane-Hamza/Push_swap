/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:51:32 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_link **stack)
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
		return;
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = last(*stack);
	second->prev->next = second;
	*stack = second;
}

void push_a_b(t_link **stack_a,t_link **stack_b)
{
    t_link *topa;

    topa = *stack_a;
    if (*stack_a != NULL)
    {
        if((*stack_a)->next != *stack_a)
        {
            *stack_a = (*stack_a)->next;
            (*stack_a)->prev = topa->prev;
            topa->prev->next = *stack_a;
        }
        else
            *stack_a = NULL;
        
        change_link(stack_b, &topa);
    }
}

void    fi_lst_or_lst_fi(t_link **stack,char type)
{
    if (type == 'f')
        *stack = (*stack)->next;
    else if (type == 'l')
        *stack = (*stack)->prev;
    else
        return ;
    
}

int	check_if_sort(t_link *stack)
{
    t_data data;
    t_link	*current;


	if (data.num_node < 1)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_data	array_to_stack(t_link **stack_a,t_data data)
{
	int	i;
    t_link *new;

	i = 0;
	data.array = malloc(data.y * sizeof(int));
	if (!data.array)
		ft_error("Error : data.array allocation faild");
	while (i < data.y)
	{
		new = create_cpy(ft_atoi(data.split[i]));
        change_link(stack_a, &new);
		data.array[i] = ft_atoi(data.split[i]);
		i++;
	}
	return (data);
}
