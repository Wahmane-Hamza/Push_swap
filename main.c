/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/25 15:33:51 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
// -------------------------------------------------
    t_link *stack_a;
    stack_a = NULL; 

    t_link *stack_b;
    stack_b = NULL;
    
// -------------------------------------------------
    if (argc < 2)
        return (0);
    else if (argc == 2)
    {
        argv = ft_split(argv[1],' ');
        argc = 0;
        while (argv[argc])
            argc++;    
    }
    add_to_a(&stack_a,argc - 1,argv);


// -------------------------------------------------

    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);
    pa_pb(&stack_a,&stack_b);

    // ss(&stack_b,&stack_a);
    // ra_rb_rra_rrb(&stack_a,'f');
    // ra_rb_rra_rrb(&stack_b,'f');
    // rr_rrr(&stack_a,&stack_b,'f');
// -------------------------------------------------
    printf("----STACK A----\n");
    t_link *break_a = stack_a;
    if (stack_a !=NULL)
    {
        while (1)
        {
            printf(" %d |",*(int *)stack_a->content);
            stack_a = stack_a->next;
            if(stack_a == break_a)
            {
                // printf(" %s |",(char *)stack_a->content);
                break;
            }   
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
            printf(" %d |",*(int *)stack_b->content);
            stack_b = stack_b->next;
            if(stack_b == break_b)
                break;
        }
    }
    else
        printf("STACK B EMPTY\n");
}