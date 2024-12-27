/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:11:06 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 15:58:22 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void *add_to_a(t_link **stack_a, int argc, char **argv) 
// {
//     t_link *new;
//     t_data  data;
//     int     *num;

//     data.num_node = 0;
//     while (argc > 0)
//     {
//         if (!check_int(argv[argc]))
//             return (NULL);
//         new = create_cpy(ft_atoi(argv[argc]));
//         data.num_node++;
//         change_link(stack_a, &new);
//         argc--;
//     }
//     if(!ft_strrchr(stack_a))
//         return (NULL);
//     sort_stack(stack_a,data.num_node);
// }

// void free_stack(t_link **stack)
// {
//     t_link *current;
//     t_link *next_node;

//     if (!stack || !(*stack))
//         return;
//     current = *stack;

//     while (1)
//     {
//         next_node = current->next;   
//         free(current);               
//         if (next_node == *stack)   
//             break;
//         current = next_node;         
//     }
//     *stack = NULL;                    
// }

// void    *check_int(char *argv)
// {
//     int j;

//     j = 0;
//     while (argv[j]) 
//     {
//         if (argv[j] < '0' || argv[j] > '9')
//             return (NULL);
//         j++;
//     }
//     return (argv);
// }