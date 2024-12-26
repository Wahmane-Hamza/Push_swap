/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:53:10 by hwahmane         ###   ########.fr       */
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

void *add_to_a(t_link **stack_a, int argc, char **argv) 
{
    t_link *new;
    t_data  data;
    int     *num;

    data.num_node = 0;
    while (argc > 0)
    {
        if (!check_int(argv[argc]))
            return (NULL);
        new = create_cpy(ft_atoi(argv[argc]));
        data.num_node++;
        change_link(stack_a, &new);
        argc--;
    }
    if(!ft_strrchr(stack_a))
        return (NULL);
    sort_stack(stack_a,data.num_node);
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