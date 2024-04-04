/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:24:33 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/03 15:34:58 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_is_positiv_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (0);
	else
		return (1);
}

int	ft_map_size_dup(char **map)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (map[i])
	{
		i++;
		size++;
	}
	return (size);
}

char	*ft_strdup_map_dup(const char *s)
{
	char	*dup;
	char	*src;
	int		len;
	int		i;
	int		j;

	src = (char *)s;
	len = ft_strlen(src) + 1;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	j = 0;
	dup[j++] = ' ';
	while (src[i])
	{
		dup[j++] = src[i];
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

char	**ft_map_dup_utils(char **map, int j, int map_size)
{
	char	**copie;
	int		i;

	copie = (char **)malloc(sizeof(char *) * (map_size + 2));
	if (!copie)
		return (NULL);
	i = 0;
	copie[i] = ft_fill_fisrt_line();
	while (map[++j] && j < map_size)
	{
		if (map[j][0] == '\n')
			continue ;
		copie[++i] = ft_strdup_map_dup(map[j]);
		if (!copie[i])
			return (ft_free_map(copie), NULL);
	}
	copie[++i] = 0;
	return (copie);
}

char	**ft_map_dup(char **map)
{
	int		j;
	int		map_size;

	map_size = ft_find_start(map) - 1;
	if (map_size < 0)
		return (NULL);
	j = map_size;
	map_size = ft_map_size_dup(map + map_size);
	map_size += j;
	return (ft_map_dup_utils(map, j, map_size));
}

//mettre une ligne de space a la fin de la map pour eviter le segfault