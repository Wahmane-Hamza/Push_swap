/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 14:12:39 by hwahmane         ###   ########.fr       */
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


int main()
{
    
// -------------------------------------------------
    t_link *node;
    t_link *node2;
    t_link *node3;

    int i = 1;
    int i2 = 2;
    int i3 = 3;


    node = malloc(sizeof(t_link));
    node->content = &i;
    
    node2 = malloc(sizeof(t_link));
    node2->content = &i2;

    node3 = malloc(sizeof(t_link));
    node3->content = &i3;


    node->next = node2;
    node2->next = node3;
    node3->next = node;

    node->prev = node3;
    node2->prev = node;
    node3->prev = node2;

// -------------------------------------------------
    t_link *list;

    list = malloc(sizeof(t_link));

// -------------------------------------------------

    swap(&node,&node2);



// -------------------------------------------------

    printf("node 1\n");
    printf("%d\n",*(int *)node->content);
    
    printf("node 2\n");
    printf("%d\n",*(int *)node2->content);

    printf("node 3\n");
    printf("%d\n",*(int *)node3->content);


    free(node);
    free(node2);
    free(node3);
}