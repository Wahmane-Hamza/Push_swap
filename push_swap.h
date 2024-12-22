/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:44 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/22 19:54:11 by hwahmane         ###   ########.fr       */
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

void push_a_b(t_link **stack_a,t_link **stack_b);
void swap(t_link **first);
void    add_to_a(t_link **stack_a,int argc, char **argv);

void    *check_int(char *argv);
t_link *create_cpy(char *str);
void    change_link(t_link **stack,t_link **new);

void sa_sb(t_link **stack);
void ss(t_link **stack_a,t_link **stack_b);
void pa_pb(t_link **first,t_link **second);

#endif