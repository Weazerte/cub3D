/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:40:16 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/04 16:35:04 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_valid_char_out(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ' && c != '\n')
		return (1);
	return (0);
}

int	ft_check_other_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (ft_valid_char_out(map[i][j]) == 1)
			{
				return (ft_putstr_fd("Error: Invalid character in map\n", 2),
					1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
