/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:45:45 by eaubry            #+#    #+#             */
/*   Updated: 2024/03/28 18:06:33 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

// check if there is only one spawn point
int	ft_check_spawn(char **map)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				spawn++;
			j++;
		}
		i++;
	}
	if (spawn != 1)
	{
		ft_putstr_fd("Error Invalid spawn\n", 2);
		return (1);
	}
	return (0);
}
