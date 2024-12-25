/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:51:54 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/25 15:25:17 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link *create_cpy(int num)
{
    int *content;
    t_link *new;

    new = malloc(sizeof(t_link));
    if (!new)
        return (NULL);
    content = malloc(2 * sizeof(int));
    if (!content)
        return (free(new),NULL);
    *content= num;
    new->content = content;
    return (new);
}

void    *check_int(char *argv)
{
    int j;

    j = 0;
    while (argv[j]) 
    {
        if (argv[j] < '0' || argv[j] > '9')
            return (NULL);
        j++;
    }
    return (argv);
}

void    change_link(t_link **stack,t_link **new)
{
    if (*stack == NULL)
    {
        *stack = *new;
        (*new)->next = *new;
        (*new)->prev = *new;
    }
    else 
    {
        (*new)->next = *stack;
        (*new)->prev = (*stack)->prev; 
        (*stack)->prev->next = *new;
        (*stack)->prev = *new;
        *stack = *new;
    }
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	i;
    int     s_len;

    s_len = 0;
    while (s1[s_len])
        s_len++;
	dst = (char *)malloc(s_len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			src_len;
	size_t			substr_len;
    int             i;

	if (!s)
		return (NULL);
    src_len = 0;
    while (s[src_len])
        src_len++;
	if (start >= src_len)
		return (ft_strdup(""));
	substr_len = src_len - start;
	if (substr_len > len)
		substr_len = len;
	ptr = (char *) malloc(substr_len + 1);
	if (!ptr) return (NULL);
    i = 0;
	while (i < substr_len && s[i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}