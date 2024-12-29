/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:15:00 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/29 16:45:45 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupp(char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(ft_strlenn(s1) + 1);
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

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdupp(s1));
	if (!s1 && s2)
		return (ft_strdupp(s2));
	if (!s1 && !s2)
		return (ft_strdupp(""));
	size = ft_strlenn(s1) + ft_strlenn(s2) + 1;
	dst = malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

int	before_n_stack(char *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	return (i);
}

int	after_n_stack(char *stack, int i)
{
	int	j;

	j = 0;
	while (stack[i])
	{
		i++;
		j++;
	}
	return (j);
}
