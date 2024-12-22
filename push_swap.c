/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 19:54:05 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa_sb(t_link **stack)
{
    swap(stack);
}

void ss(t_link **stack_a,t_link **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

void pa_pb(t_link **first,t_link **second)
{
    push_a_b(first,second);
}

