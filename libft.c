/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:52:28 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/26 19:00:24 by hwahmane         ###   ########.fr       */
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
	int	i;
	int	k;
	int	sign;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	k = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) +(str[i] - 48);
		i++;
	}
	return (k * sign);
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