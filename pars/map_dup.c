/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:24:33 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/21 14:19:35 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int	ft_find_start(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		if (map[i][j] == '1')
			return (i);
		i++;
	}
	return (0);
}

char	**ft_map_dup(char **map)
{
	int		i;
	int		j;
	char	**copie;
	int		map_size;

	map_size = ft_find_start(map);
	map_size--;
	j = map_size;
	while (map[map_size])
	{
		if (map[map_size] == 0)
			continue ;
		map_size++;
	}
	copie = (char **)malloc(sizeof(char *) * (map_size + 1));
	i = -1;
	while (map[j++])
	{
		if (map[j] == 0)
			continue ;
		copie[++i] = ft_strdup(map[j]);
	}
	copie[i] = 0;
	return (copie);
}
