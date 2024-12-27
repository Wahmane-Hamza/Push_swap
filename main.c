/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:50:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:56:10 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_data	data;
	t_link	*stack_a;
	t_link	*stack_b;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	data = put_on_it(av);
	data = array_to_stack(&stack_a, data);
	if (!check_if_sort(stack_a))
		return (0);
	data = bubble_sort(data);
	sort_stack(data, &stack_a, &stack_b);
	// exit (0);

// -------------------------------------------------
    printf("----STACK A----\n");
    t_link *break_a = stack_a;
    if (stack_a !=NULL)
    {
        while (1)
        {
            printf(" %d |",stack_a->content);
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
            printf(" %d |",stack_b->content);
            stack_b = stack_b->next;
            if(stack_b == break_b)
                break;
        }
    }
    else
        printf("STACK B EMPTY\n");
}