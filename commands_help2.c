/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:21:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:04:29 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

t_data	put_on_it(char **av)
{
	t_data	data;
	int		i;

	i = 1;
	data.args = NULL;
	while (av[i])
	{
		data.args = ft_strjoin(data.args, av[i]);
		i++;
	}
	data.split = ft_split(data.args, ' ');
	data = check_all(data);
	return (data);
}

void	check_long(char *str)
{
	int	o;
	int	i;

	o = 0;
	i = 0;
	while (str[o] == '0')
		o++;
	while (str[i])
		i++;
	if (i - o > 11)
		ft_error("Error\n");
}

t_data	check_all(t_data data)
{
	long	x;
	long	i;

	i = 0;
	data.y = 0;
	while (data.split[data.y])
	{
		check_long(data.split[data.y]);
		x = ft_atoi(data.split[data.y]);
		i = data.y;
		while (data.split[i])
		{
			if (data.split[i + 1] == NULL)
				break ;
			if (x == ft_atoi(data.split[i + 1]))
				ft_error("Error\n");
			i++;
		}
		data.y++;
	}
	return (data);
}

void free_stack(t_link **stack)
{
    t_link *current;
    t_link *next_node;

    if (!stack || !(*stack))
        return;
    current = *stack;

    while (1)
    {
        next_node = current->next;   
        free(current);               
        if (next_node == *stack)   
            break;
        current = next_node;         
    }
    *stack = NULL;                    
}



