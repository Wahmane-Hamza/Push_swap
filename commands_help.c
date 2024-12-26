/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:51:54 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:53:15 by hwahmane         ###   ########.fr       */
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

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != stack)
		current = current->next;
	return (current);
}