/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:45:45 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/20 17:35:12 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

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
		ft_printf("Error Invalid spawn\n");
		return (1);
	}
	return (0);
}
