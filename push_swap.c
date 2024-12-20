/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/20 16:39:12 by hwahmane         ###   ########.fr       */
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


int main()
{
    t_link *node;
    t_link *node2;
    t_link *node3;
    
    node = malloc(sizeof(t_link));
    node->content = cpy("hello");
    
    node2 = malloc(sizeof(t_link));
    node2->content = cpy("hello2");

    node3 = malloc(sizeof(t_link));
    node3->content = cpy("hello3");


    node->next = node2;
    node2->next = node3;
    node3->next = node;
;
    node->prev = node3;
    node2->prev = node;
    node3->prev = node2;


    printf("node 1\n");
    printf("%s\n", (char*)node->content);

    printf("%s\n",(char*)node->next->content);

    printf("%s\n",(char*)node->prev->content);

    printf("node 2\n");    
    printf("%s\n", (char*)node2->content);

    printf("%s\n",(char*)node2->next->content);

    printf("%s\n",(char*)node2->prev->content);
    
    printf("node 3\n");
    printf("%s\n", (char*)node3->content);

    printf("%s\n",(char*)node3->next->content);

    printf("%s\n",(char*)node3->prev->content);

    free(node->content);
    free(node);
    free(node2->content);
    free(node2);
    free(node3->content);
    free(node3);
}