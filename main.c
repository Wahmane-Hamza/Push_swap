/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 19:57:28 by hwahmane         ###   ########.fr       */
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

    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_b,&stack_a);

    ss(&stack_b,&stack_a);

// -------------------------------------------------
    printf("----STACK A----\n");
    t_link *break_a = stack_a;
    if (stack_a !=NULL)
    {
        while (1)
        {
            printf(" %s |",(char *)stack_a->content);
            stack_a = stack_a->next;
            if(stack_a == break_a)
                break;
        }
    }
    else
        printf("STACK A EMPTY\n\n\n");

    printf("\n----STACK B----\n");
    t_link *break_b = stack_b;
    if (stack_b !=NULL)
    {   
        while (1)
        {   
            printf("%s |",(char *)stack_b->content);
            stack_b = stack_b->next;
            if(stack_b == break_b)
                break;
        }
    }
    else
        printf("STACK B EMPTY\n");
}