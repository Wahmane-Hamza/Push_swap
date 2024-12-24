/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:19:52 by hwahmane          #+#    #+#             */
/*   Updated: 2024/12/24 16:08:14 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	num_strings;
	int	i;

	i = 0;
	num_strings = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_strings++;
		i++;
	}
	return (num_strings);
}

static char	**free_array(char **array, int j)
{
	while (j > 0)
	{
		j--;
		free(array[j]);
	}
	free (array);
	return (NULL);
}

static char	**fill_array(char const *s, char c, char **array, int i)
{
	int		k;
	int		j;
	char	*elem;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i] != '\0')
		{
			k++;
			i++;
		}
		if (k > 0)
		{
			elem = ft_substr(s, i - k, k);
			if (!elem)
				return (free_array(array, j));
			array[j++] = elem;
		}
		if (s[i] != '\0')
			i++;
	}
	array[j] = NULL;
	return (array);
}

    char	**ft_split(char const *s, char c)
    {
        char	**array;
        int		i;

        if (!s)
            return (NULL);
        array = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
        if (!array)
            return (NULL);
        i = 0;
        return (fill_array(s, c, array, i));
    }
