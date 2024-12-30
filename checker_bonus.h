/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:44:13 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/30 13:38:28 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_link
{
	int				content;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct s_data
{
	int				lstsize;
	int				i;
	int				j;
	int				sign;
	long			result;
	long			y;
	char			*args;
	char			**split;
	int				*array;
	int				mpos;
	int				max;
}					t_data;

// push swap commands
void				sa_sb(t_link **stack, int type);
void				ss(t_link **stack_a, t_link **stack_b, int flag);
void				pa_pb(t_link **first, t_link **second, int flag);
void				ra_rb_rra_rrb(t_link **stack, char type, int flag);
void				rr_rrr(t_link **stack_a, t_link **stack_b, char type,
						int flag);

// push swap commands 2
void				push_a_b(t_link **f_stack, t_link **s_stack);
void				swap(t_link **first);
t_data				array_to_stack(t_link **stack_a, t_data data);
void				fi_lst_or_lst_fi(t_link **stack, char type, int flag);
int					check_if_sort(t_link *stack);

// push swap commands 3
t_data				bubble_sort(t_data data);

// commands help
t_link				*ft_lstnew(int num);
void				change_link(t_link **stack, t_link **new, char type);
t_link				*last(t_link *stack);
void				ft_check_str(char *str);
void				check_revers(t_link **stack_a);

// commands help 2
void				ft_error(char *str);
t_data				put_on_it(char **av);
t_data				check_all(t_data data);
int					get_min_pos(t_link *stack);

// libft functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *s1);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
char				*ft_strjoin(char *stack, char *buffer);
char				**ft_split(char const *s, char c);

// algo
int					sort_stack(t_data data, t_link **stack_a, t_link **stack_b);
void				sort_3(t_link **stack_a);
void				push_min(t_link **stack_a, t_link **stack_b);
void				sort_4_5(t_data data, t_link **stack_a, t_link **stack_b);
void				full_sort(t_data data, t_link **stack_a, t_link **stack_b);

// full sort functions
int					lstsize(t_link *lst);
void				check_swap(t_link **stack);
t_data				find_max(t_link *stack);
void				last_sort(t_link **stack_a, t_link **stack_b, t_data data);
int					get_rang(t_data data);

#endif