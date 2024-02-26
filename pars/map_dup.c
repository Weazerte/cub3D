/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weaz <weaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:24:33 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/26 13:25:00 by weaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int	ft_is_positiv_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (0);
	else
		return (1);
}

int	ft_find_start(char **map)
{
	int	i;
	int	j;
	int k;
	int test;

	i = -1;
	while (map[++i])
	{
		test = 0;
		j = ft_skip_space(map[i]);
		if (map[i][j] == '1')
		{
			k = i - 1;
			while(map[++k])
			{
				j = ft_skip_space(map[k]);
				if (ft_is_positiv_digit(map[k][j]) == 1)
					test = 1;
			}
			if (test == 0)
				return (i);
		}
	}
	return (-1);
}

int	ft_map_size_dup(char **map)
{
	int i;
	int size;
	
	size = 0;
	i = 0;
	while (map[i])
	{
		i++;
		size++;
	}
	return (size);
}

char	**ft_map_dup(char **map)
{
	int		i;
	int		j;
	char	**copie;
	int		map_size;

	map_size = ft_find_start(map);
	if (map_size == -1)
		return (NULL);
	map_size--;
	j = map_size;
	map_size = ft_map_size_dup(map + map_size);
	copie = (char **)malloc(sizeof(char *) * (map_size + 1));
	map_size += j;
	i = -1;
	while (map[++j] && j < map_size)
	{
		if (map[j][0] == '\n')
			continue ;
		copie[++i] = ft_strdup(map[j]);
	}
	copie[i] = 0;
	return (copie);
}
