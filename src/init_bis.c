/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:33 by thenry            #+#    #+#             */
/*   Updated: 2024/03/20 16:02:51 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	init_dir(t_rcast *raycast, t_tibs *tibs)
{
	if (tibs->direction == 'N')
	{
		raycast->dir_x = -1;
		raycast->dir_y = 0;
	}
	else if (tibs->direction == 'S')
	{
		raycast->dir_x = 1;
		raycast->dir_y = 0;
	}
	else if (tibs->direction == 'E')
	{
		raycast->dir_x = 0;
		raycast->dir_y = 1;
	}
	else if (tibs->direction == 'W')
	{
		raycast->dir_x = 0;
		raycast->dir_y = -1;
	}
}

void	init_plane(t_rcast *raycast, t_tibs *tibs)
{
	if (tibs->direction == 'N')
	{
		raycast->plane_x = 0;
		raycast->plane_y = 0.66;
	}
	else if (tibs->direction == 'S')
	{
		raycast->plane_x = 0;
		raycast->plane_y = -0.66;
	}
	else if (tibs->direction == 'E')
	{
		raycast->plane_x = 0.66;
		raycast->plane_y = 0;
	}
	else if (tibs->direction == 'W')
	{
		raycast->plane_x = -0.66;
		raycast->plane_y = 0;
	}
}
