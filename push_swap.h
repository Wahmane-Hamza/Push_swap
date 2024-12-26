/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:44 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 18:57:15 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_link
{
    int            content;
    struct s_link *next;
    struct s_link *prev;
}   t_link;

typedef struct s_data
{
    int num_node;
}   t_data;


void push_a_b(t_link **stack_a,t_link **stack_b);
void swap(t_link **first);
void    *add_to_a(t_link **stack_a,int argc, char **argv);
void    fi_lst_or_lst_fi(t_link **stack,char type);

char	**ft_split(char const *s, char c);
void    *check_int(char *argv);
t_link *create_cpy(int num);
void    change_link(t_link **stack,t_link **new);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
t_link	*last(t_link *stack);
size_t	ft_strlen(const char *str);
void	ft_error(char *str);

void	*ft_strrchr(t_link **stack_a);
int	ft_atoi(const char *str);

// algo
int sort_stack(t_link **stack,int num_node);
void	sort_3(t_link **stack_a);

void sa_sb(t_link **stack,int type);
void ss(t_link **stack_a,t_link **stack_b);
void pa_pb(t_link **first,t_link **second);
void    ra_rb_rra_rrb(t_link **stack,char type);
void    rr_rrr(t_link **stack_a,t_link **stack_b,char type);

#endif