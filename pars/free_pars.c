/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:58:01 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/21 14:20:14 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void	ft_memdel(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_tibs(t_tibs *tibs)
{
	if (tibs->map)
		ft_free_map(tibs->map);
	if (tibs->north_path)
		free(tibs->north_path);
	if (tibs->south_path)
		free(tibs->south_path);
	if (tibs->east_path)
		free(tibs->east_path);
	if (tibs->west_path)
		free(tibs->west_path);
}
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

void	ft_free_pars(t_tibs *tibs, char **map, char **map2)
{
	ft_free_map(map);
	ft_free_map(map2);
	ft_free_tibs(tibs);
}
