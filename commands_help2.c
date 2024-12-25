/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:21:48 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/25 15:31:40 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c2;
	int				slen;

	slen = ft_strlen(s);
	c2 = c;
	while (slen >= 0)
	{
		if (s[slen] == c2)
			return ((char *)&s[slen]);
		slen--;
	}
	return (NULL);
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