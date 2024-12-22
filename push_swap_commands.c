/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 20:41:46 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_link **first)
{
    void *cup;
    
    cup = (*first)->content;
    (*first)->content = (*first)->next->content;
    (*first)->next->content = cup;
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

void add_to_a(t_link **stack_a, int argc, char **argv) 
{
    int i;
    t_link *new;

    i = 1;
    while (i < argc) 
    {
        if (!check_int(argv[i]))
            return ;
        new = create_cpy(argv[i]);
        change_link(stack_a, &new);
        i++;
    }
}

void    first_last(t_link **stack)
{
    
}