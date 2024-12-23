/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/23 14:35:56 by hwahmane         ###   ########.fr       */
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

void    fi_lst_or_lst_fi(t_link **stack,char type)
{
    if (type == 'f')
        *stack = (*stack)->next;
    else if (type == 'l')
        *stack = (*stack)->prev;
    else
        return ;
    
}