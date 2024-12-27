/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:51:54 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 16:15:50 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *ft_lstnew(int num)
{
    t_link *new;

    new = malloc(sizeof(t_link));
    if (!new)
        ft_error("allocation lstnew faild");
    new->content = num;
    return (new);
}

void    change_link(t_link **stack,t_link **new, char type)
{
    t_link  *cup;

    if (*stack == NULL)
    {
        *stack = *new;
        (*new)->next = *new;
        (*new)->prev = *new;
    }
    else if (type == 'b')
    {
        (*new)->next = *stack;
        (*new)->prev = (*stack)->prev;
        (*stack)->prev->next = *new;
        (*stack)->prev = *new;
    }
    else if (type == 'f')
    {
        cup = (*stack);
        *stack = *new;
        (*new)->next = cup;
        (*new)->prev = cup->prev;
        cup->prev->next = *new;
        cup->prev = *new;
    }
}

t_link	*last(t_link *stack)
{
	t_link	*current;
    t_data data;

	if (!stack)
		return (NULL);
	current = stack;
    data.lstsize = 0;
	while (current->next != stack)
    {
		current = current->next;
        data.lstsize++;
    }
	return (current);
}

void	ft_check_str(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			x++;
		i++;
	}
	if (x == 0)
		ft_error("Error\n");
}

void	check_revers(t_link **stack_a)
{
	t_link	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = *stack_a;
	len = lstsize(*stack_a);
	while ((tmp)->next)
	{
		if ((tmp)->content > (tmp)->next->content)
			i++;
		tmp = (tmp)->next;
	}
	i++;
	if (i == len)
		ra_rb_rra_rrb(stack_a, 'l', 1);
	else
		ra_rb_rra_rrb(stack_a, 'f', 1);
}
// void	*ft_strrchr(t_link **stack_a)
// {
// 	t_link  *break_a;
//     t_link  *break_c;
//     t_link  *stack_bef;
//     int     check;

// 	break_a = *stack_a;
//     while (1)
//     {
//         check = (*stack_a)->content;
//         break_c = *stack_a;
//         *stack_a = (*stack_a)->next;
//         stack_bef = *stack_a;
//         while (break_c != *stack_a)
//         {
//             if (check == (*stack_a)->content)
//             {
//                 free_stack(stack_a);
//                 return (NULL);
//             }
//             *stack_a = (*stack_a)->next;
//         }
//         *stack_a = stack_bef;
//         if (break_a == *stack_a)
//             break;
//     }
// }