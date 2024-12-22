/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 16:04:08 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *cpy(char *str)
{
    int j;
    char *ptr;
    int i;

    j = 0;
    while (str[j])
        j++;
    ptr = malloc(j + 1);
    if (!ptr)
        return (NULL);

    i = 0;
    while (str[i])
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i]='\0';
    return (ptr);
}

void swap(t_link **first,t_link **second)
{
    void *cup;
    
    cup = (*first)->content;
    (*first)->content = (*second)->content;
    (*second)->content = cup;
}

void pushb(t_link **froma,t_link **tob)
{
    t_link *topa = *froma;

    *froma = (*froma)->next;

    (*froma)->prev = topa->prev;

    topa->prev->next = *froma;

    topa->next = *tob;
    *tob = topa;
    
}

void add_to_a(t_link **stack_a, int argc, char **argv) {
    int i = 1;
    t_link *new;
    t_link *old_node = NULL;

    while (i < argc) 
    {
        int j = 0;
        while (argv[i][j]) 
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return; 
            j++;
        }
        new = malloc(sizeof(t_link));
        if (!new) return;
        new->content = cpy(argv[i]);
        if (*stack_a == NULL) 
        {
            *stack_a = new;
            new->next = new;
            new->prev = new;
        } 
        else 
        {
            old_node = *stack_a;
            new->next = old_node;
            new->prev = old_node->prev; 
            old_node->prev->next = new;
            old_node->prev = new;
            *stack_a = new;
        }
        i++;
    }
}