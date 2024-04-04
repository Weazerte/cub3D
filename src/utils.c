/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibzer <tibzer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:35:19 by tibzer            #+#    #+#             */
/*   Updated: 2024/03/27 19:35:37 by tibzer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	get_max_rows(char **map)
{
	int	nb_rows;

	nb_rows = 0;
	while (map[nb_rows])
		nb_rows++;
	return (nb_rows);
}

int	get_max_len(char **map)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j > tmp)
			tmp = j;
		i++;
	}
	return (tmp);
}
