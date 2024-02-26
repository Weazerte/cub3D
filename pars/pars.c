/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weaz <weaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:24 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/22 01:43:35 by weaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

//check if the map file is valid (.cub)
int	ft_check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] != 'b' || name[i - 2] != 'u' || name[i - 3] != 'c' || name[i
		- 4] != '.')
	{
		ft_printf("Error Invalid file name\n");
		return (1);
	}
	return (0);
}

// static void    ft_print_map(char **map)
// {
//     int i;

//     i = 0;
//     while (map[i])
//     {
//         ft_printf("%s", map[i]);
//         i++;
//     }
//     ft_printf("\n");
// }

int	ft_init_tibs(t_tibs *tibs, char **map)
{
    ft_bzero(tibs, sizeof(*tibs));
	tibs->direction = ft_wich_direction(map);
	tibs->map = ft_map_dup(map);
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
		return (ft_free_map(map), 1);
	if (ft_check_spawn(map_4_test) == 1)
		return (ft_free_map(map), ft_free_map(map_4_test), 1);
	ft_init_tibs(tibs, map);
	// ft_print_map(tibs->map);
	if (ft_check_texture(map, tibs) == 1)
		return (ft_free_map(map), ft_free_map(map_4_test), 1);
	if (ft_check_outline(map_4_test, tibs->direction) == 1)
		return (ft_free_map(map), ft_free_map(map_4_test), 1);
	return (ft_free_map(map), ft_free_map(map_4_test), 0);
}
//
//leak
//fix the tab