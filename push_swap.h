/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:16:44 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:55:31 by hwahmane         ###   ########.fr       */
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
    int     num_node;
    int		i;
	int		j;
	int		sign;
	long	result;
    long	y;
    char	*args;
    char	**split;
    int		*array;
}   t_data;


void push_a_b(t_link **stack_a,t_link **stack_b);
void swap(t_link **first);
t_data	array_to_stack(t_link **stack_a,t_data data);
void    fi_lst_or_lst_fi(t_link **stack,char type);
int	check_if_sort(t_link *stack);

t_data	bubble_sort(t_data data);


void    *check_int(char *argv);
t_link *create_cpy(int num);
void    change_link(t_link **stack,t_link **new);
t_link	*last(t_link *stack);
void	*ft_strrchr(t_link **stack_a);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);
char	*ft_strjoin(char *stack, char *buffer);

char	**ft_split(char const *s, char c);

void	ft_error(char *str);
t_data	put_on_it(char **av);
void	check_long(char *str);

// algo
int sort_stack(t_data data, t_link **stack_a, t_link **stack_b);
void	sort_3(t_link **stack_a);

void sa_sb(t_link **stack,int type);
void ss(t_link **stack_a,t_link **stack_b);
void pa_pb(t_link **first,t_link **second);
void    ra_rb_rra_rrb(t_link **stack,char type);
void    rr_rrr(t_link **stack_a,t_link **stack_b,char type);

#endif