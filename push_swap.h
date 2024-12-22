/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:44 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 15:33:38 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_link
{
    void    *content;
    struct s_link *next;
    struct s_link *prev;
}   t_link;

void pushb(t_link **froma,t_link **tob);
void swap(t_link **first,t_link **second);
char *cpy(char *str);
void    add_to_a(t_link **stack_a,int argc, char **argv);

#endif