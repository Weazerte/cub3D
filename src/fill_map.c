/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:08 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/03 15:34:13 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"
#include "../get_next_line/get_next_line.h"

//for ft_map_dup
char	*ft_fill_fisrt_line(void)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * (100));
	if (!line)
		return (NULL);
	i = -1;
	while (i < 98)
		line[++i] = ' ';
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//for ft_map_dup
int	ft_find_start(char **map)
{
	int	i;
	int	j;
	int	k;
	int	test;

	i = -1;
	while (map[++i])
	{
		test = 0;
		j = ft_skip_space(map[i]);
		if (map[i][j] == '1')
		{
			k = i - 1;
			while (map[++k])
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

char	*ft_fill_last_line(char **map, int i)
{
	int		j;
	int		size;
	char	*line;

	size = 0;
	while (map[i][size])
		size++;
	size++;
	i++;
	line = malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (j < size)
		line[++j] = ' ';
	line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

int	ft_map_size(char *map_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error map name\n", 2);
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

char	**ft_fill_map(char *map_name)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error map name\n", 2), NULL);
	map = malloc(sizeof(char *) * (ft_map_size(map_name) + 2));
	if (!map)
		return (close(fd), ft_putstr_fd("Error Malloc\n", 2), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = ft_fill_last_line(map, i - 1);
	map[++i] = NULL;
	close(fd);
	return (map);
}
