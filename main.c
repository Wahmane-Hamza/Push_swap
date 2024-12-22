/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 16:01:17 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    
// -------------------------------------------------
    t_link *stack_a;
    stack_a = NULL;
    add_to_a(&stack_a,argc,argv);
    
// -------------------------------------------------
    t_link *stack_b;
    stack_b = NULL;

// -------------------------------------------------

    // swap(&node,&node2);
    // pushb(&stack_a,&stack_b);


// -------------------------------------------------
    printf("----STACK A----\n");
    if (stack_a !=NULL)
    {   
        int j = 1;
        while (j < argc)
        {   
            printf(" %s |",(char *)stack_a->content);
            stack_a = stack_a->next;
            j++;
        }
    }
    else
        printf("STACK A EMPTY\n\n\n");

    printf("\n----STACK B----\n");
    if (stack_b !=NULL)
    {   
        int j = 1;
        while (j < argc)
        {   
            printf("%s |",(char *)stack_b->content);
            stack_b = stack_b->next;
            j++;
        }
    }
    else
        printf("STACK B EMPTY\n");
}