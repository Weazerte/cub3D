/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:24 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/04 13:59:51 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

//check if the map file is valid (.cub)
int	ft_check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] != 'b' || name[i - 2] != 'u' || name[i - 3] != 'c' || name[i
			- 4] != '.')
		return (ft_putstr_fd("Error: Invalid file name\n", 2), 1);
	return (0);
}

//check if there is more than texture and rgb before the map
int	ft_check_plus(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space2(map[i]);
		if (map[i][j] == '1' || map[i][j] == '0')
			return (0);
		if (j != ft_strlen_verif(map[i]))
			return (ft_putstr_fd("Error: Invalid Additional Map Information\n",
					2), 1);
		i++;
	}
	return (1);
}

int	ft_init_tibs(t_tibs *tibs, char **map)
{
	ft_bzero(tibs, sizeof(*tibs));
	tibs->direction = ft_wich_direction(map);
	tibs->map = ft_map_dup(map);
	if (!tibs->map)
		return (1);
	return (0);
}

int	ft_pars(t_tibs *tibs, char **av)
{
	char	**map;
	char	**map_4_test;

	if (ft_check_name(av[1]) == 1)
		return (1);
	map = ft_fill_map(av[1]);
	if (map == NULL)
		return (1);
	map_4_test = ft_map_dup(map);
	if (!map_4_test)
		return (ft_putstr_fd("Error map\n", 2), ft_free_map(map), 1);
	if (ft_check_spawn(map_4_test) == 1 || ft_init_tibs(tibs, map) == 1)
		return (ft_free_map(map), ft_free_map(map_4_test), 1);
	if (ft_check_texture(map, tibs) == 1)
		return (ft_free_pars(tibs, map, map_4_test), 1);
	if (ft_check_plus(map) == 1)
		return (ft_free_pars(tibs, map, map_4_test), 1);
	if (ft_check_outline(map_4_test, tibs->direction) == 1)
		return (ft_free_pars(tibs, map, map_4_test), 1);
	tibs->res_x = ft_find_map_start_i(tibs->map);
	tibs->res_y = ft_find_map_start_j(tibs->map);
	ft_replace_start(tibs->map, tibs->res_x, tibs->res_y);
	return (ft_free_map(map), ft_free_map(map_4_test), 0);
}
