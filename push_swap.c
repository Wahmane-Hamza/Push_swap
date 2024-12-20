/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:21 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/20 15:39:14 by hwahmane         ###   ########.fr       */
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


    // void	ft_lstadd_front(t_link **lst, t_link *new)
    // {
    // 	if (lst || new)
    // 	{
    // 		new->next = *lst;
    // 		*lst = new;
    // 	}
    // }


int main()
{
    // t_link *node;
    t_link *node2;
    // t_link *node3;
    // node->content = malloc(sizeof(t_link));
    // node->next = NULL;
    // node->prev = NULL;
    
    node2->content = malloc(sizeof(t_link));
    if (!node2->content)
        return (NULL);
    // node2->next = NULL;
    // node2->prev = NULL;

    // node3->content = malloc(sizeof(t_link));
    // node3->next = NULL;
    // node3->prev = NULL;

    // node->content = cpy("hello");
    node2->content = cpy("hello2");
    // node3->content = cpy("hello3");

    // ft_lstadd_front(&node,node2);
    // ft_lstadd_front(&node,node3);



    printf("%s\n",(char*)node2->content);
    
    // if (node2->next = NULL)
    //     printf("NULL");
    // else
    //     printf("%s\n",(char*)node2->next);
        
    // if (node2->prev = NULL)
    //     printf("NULL");
    // else
    //     printf("%s\n",(char*)node2->prev);
    
    
    
}