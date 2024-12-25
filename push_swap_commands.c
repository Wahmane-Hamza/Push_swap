/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:58 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/25 15:43:28 by hwahmane         ###   ########.fr       */
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
    t_link *new;
    t_link  *break_a;
    t_link  *break_c;
    int     check;

    while (argc >= 0)
    {
        if (!check_int(argv[argc]))
            return ;
        new = create_cpy(ft_atoi(argv[argc]));
        change_link(stack_a, &new);
        argc--;
    }
    break_a = *stack_a;
    while (1)
    {
        check = (*stack_a)->content;
        while (break_a != stack_a)
        {
            
        }
        
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