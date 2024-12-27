/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:52:28 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/27 11:07:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	t_data	data;

	data.i = 0;
	data.sign = 1;
	data.result = 0;
	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
		ft_error("Error\n");
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
		ft_error("Error\n");


	
	data.result *= data.sign;
	if (data.result > 2147483647 || data.result < -2147483648)
		ft_error("Error\n");
	return (data.result);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	i;
    int     s_len;

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
	char			*ptr;
	size_t			src_len;
	size_t			substr_len;
    int             i;

	if (!s)
		return (NULL);
    src_len = ft_strlen(s);
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

char	*ft_strjoin(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	size_t	buffer_len;

	ft_check_str(buffer);
	stack_len = ft_strlenn(stack);
	buffer_len = ft_strlenn(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len + 2);
	if (!str)
		ft_error("strjoinn allocation faild");
	while (++i < stack_len && stack)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < buffer_len)
		str[i + j] = buffer[j];
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	return (free(stack), str);
}