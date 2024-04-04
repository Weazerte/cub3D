/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:40:59 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/03 14:58:04 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_find_map_start_j(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_find_map_start_i(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_check_next(char **map, int x, int y, int row_col[2])
{
	if (x + 1 < row_col[0] && map[x + 1][y] && (map[x + 1][y] != '0' && map[x
			+ 1][y] != '1'))
		return (1);
	if (x - 1 >= 0 && map[x - 1][y] && (map[x - 1][y] != '0' && map[x
			- 1][y] != '1'))
		return (1);
	if (y + 1 < row_col[1] && map[x][y + 1] && (map[x][y + 1] != '0' && map[x][y
			+ 1] != '1'))
		return (1);
	if (y - 1 >= 0 && map[x][y - 1] && (map[x][y - 1] != '0' && map[x][y
			- 1] != '1'))
		return (1);
	return (0);
}

int	ft_flood_fill(char **map, char c, int x, int y)
{
	int	row_col[2];

	if (map[x][y] != '0' && map[x][y] != '1')
		return (1);
	if (map[x][y] == '1')
		return (0);
	row_col[0] = 0;
	while (map[++row_col[0]])
		;
	row_col[1] = 0;
	while (map[x][++row_col[1]])
		;
	if (ft_check_next(map, x, y, row_col) == 1)
		return (1);
	map[x][y] = '1';
	if (ft_flood_fill(map, c, x + 1, y) == 1)
		return (1);
	if (ft_flood_fill(map, c, x - 1, y) == 1)
		return (1);
	if (ft_flood_fill(map, c, x, y + 1) == 1)
		return (1);
	if (ft_flood_fill(map, c, x, y - 1) == 1)
		return (1);
	return (0);
}

int	ft_check_outline(char **map, char c)
{
	int	x;
	int	y;

	x = ft_find_map_start_i(map);
	y = ft_find_map_start_j(map);
	ft_replace_start(map, x, y);
	if (ft_flood_fill(map, c, x, y) == 1)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (1);
	}
	if (ft_check_other_char(map) == 1)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (1);
	}
	return (0);
}
