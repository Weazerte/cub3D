/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:52:03 by eaubry            #+#    #+#             */
/*   Updated: 2024/03/28 17:19:36 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	return (i);
}

int	ft_skip_space2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
	{
		if (str[i + 1] == 0)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strlen_verif(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == 0)
			return (i);
		i++;
	}
	return (i);
}

int	ft_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (0);
	return (1);
}

char	ft_wich_direction(char **map)
{
	char	direction;
	int		i;
	int		j;

	direction = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				direction = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (direction);
}
