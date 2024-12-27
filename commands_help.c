/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:51:54 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:20:31 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *create_cpy(int num)
{
    t_link *new;

    new = malloc(sizeof(t_link));
    if (!new)
        return (NULL);
    new->content = num;
    return (new);
}

void    *check_int(char *argv)
{
    int j;

    j = 0;
    while (argv[j]) 
    {
        if (argv[j] < '0' || argv[j] > '9')
            return (NULL);
        j++;
    }
    return (argv);
}

void    change_link(t_link **stack,t_link **new)
{
    if (*stack == NULL)
    {
        *stack = *new;
        (*new)->next = *new;
        (*new)->prev = *new;
    }
    else 
    {
        (*new)->next = *stack;
        (*new)->prev = (*stack)->prev; 
        (*stack)->prev->next = *new;
        (*stack)->prev = *new;
        *stack = *new;
    }
}

t_link	*last(t_link *stack)
{
	t_link	*current;
    t_data data;

	if (!stack)
		return (NULL);
	current = stack;
    data.num_node = 0;
	while (current->next != stack)
    {
		current = current->next;
        data.num_node++;
    }
	return (current);
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