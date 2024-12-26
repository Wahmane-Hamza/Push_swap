/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:21:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:53:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void free_stack(t_link **stack)
{
    t_link *current;
    t_link *next_node;

    if (!stack || !(*stack))
        return;
    current = *stack;

    while (1)
    {
        next_node = current->next;   
        free(current);               
        if (next_node == *stack)   
            break;
        current = next_node;         
    }
    *stack = NULL;                    
}

void	*ft_strrchr(t_link **stack_a)
{
	t_link  *break_a;
    t_link  *break_c;
    t_link  *stack_bef;
    int     check;

	break_a = *stack_a;
    while (1)
    {
        check = (*stack_a)->content;
        break_c = *stack_a;
        *stack_a = (*stack_a)->next;
        stack_bef = *stack_a;
        while (break_c != *stack_a)
        {
            if (check == (*stack_a)->content)
            {
                free_stack(stack_a);
                return (NULL);
            }
            *stack_a = (*stack_a)->next;
        }
        *stack_a = stack_bef;
        if (break_a == *stack_a)
            break;
    }
}

