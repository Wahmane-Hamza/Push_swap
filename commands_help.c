/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:51:54 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/23 13:39:00 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *create_cpy(char *str)
{
    int j;
    char *content;
    t_link *new;
    int i;

    j = 0;
    while (str[j])
        j++;
    new = malloc(sizeof(t_link));
    if (!new)
        return (NULL);
    content = malloc(j + 1);
    if (!content)
        return (free(new),NULL);
    i = 0;
    while (str[i])
    {
        content[i] = str[i];
        i++;
    }
    content[i]='\0';
    new->content = content;
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

