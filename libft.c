/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:52:28 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/01 14:58:57 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, t_data data, t_link **stack_a, t_link **stack_b)
{
	data.i = 0;
	data.sign = 1;
	data.result = 0;
	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
		ft_error("Error\n", data, stack_a, stack_b);
	if (str[data.i] == '-' || str[data.i] == '+')
	{
		if (str[data.i] == '-')
			data.sign = -1;
		data.i++;
	}
	while ((str[data.i] >= '0' && str[data.i] <= '9'))
	{
		data.result = data.result * 10 + (str[data.i] - '0');
		data.i++;
	}
	if (str[data.i])
		ft_error("Error\n", data, stack_a, stack_b);
	data.result *= data.sign;
	if (data.result > 2147483647 || data.result < -2147483648)
		ft_error("Error\n", data, stack_a, stack_b);
	return (data.result);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	i;
	int		s_len;

	s_len = ft_strlen(s1);
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
	char	*ptr;
	size_t	src_len;
	size_t	substr_len;
	size_t	i;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	substr_len = src_len - start;
	if (substr_len > len)
		substr_len = len;
	ptr = (char *)malloc(substr_len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < substr_len && s[i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}

char	*ft_strjoin(char *buffer, t_data data, t_link **stack_a,
		t_link **stack_b)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	size_t	buffer_len;

	ft_check_str(buffer, data, stack_a, stack_b);
	stack_len = ft_strlen(data.args);
	buffer_len = ft_strlen(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len + 2);
	if (!str)
		return (NULL);
	while (++i < stack_len && data.args)
		str[i] = data.args[i];
	str[i] = '\0';
	j = -1;
	while (++j < buffer_len)
		str[i + j] = buffer[j];
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	return (free(data.args), str);
}
