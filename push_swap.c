/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:58:44 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa_sb(t_link **stack,int type)
{
    if (!(*stack))
        ft_error("ERROR STACK EMPTY");
    if (type = 1)
        write(1,"sa\n",3);
    else if (type = 2)
        write(1,"sb\n",3);
    swap(stack);
}

void ss(t_link **stack_a,t_link **stack_b)
{
    if (!(*stack_a) || !(*stack_b))
        ft_error("ERROR STACK_A OR STACK_B EMPTY");
    swap(stack_a);
    swap(stack_b);
}

void pa_pb(t_link **first,t_link **second)
{
    if (!(*first))
        ft_error("ERROR STACK_A OR STACK_B EMPTY");
    push_a_b(first,second);
}

void    ra_rb_rra_rrb(t_link **stack,char type)
{
    if (!(stack))
        ft_error("ERROR STACK EMPTY");
    fi_lst_or_lst_fi(stack,type);
}

void    rr_rrr(t_link **stack_a,t_link **stack_b,char type)
{
    if (!(stack_a) || !(stack_b))
        ft_error("ERROR STACK_A OR STACK_B EMPTY");
    fi_lst_or_lst_fi(stack_a,type);
    fi_lst_or_lst_fi(stack_b,type);
}
