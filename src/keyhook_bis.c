/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:47:49 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 15:49:00 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	key_look_right(t_info *cub)
{
	cub->raycast->old_dir_x = cub->raycast->dir_x;
	cub->raycast->dir_x = cub->raycast->dir_x * cos(-(cub->raycast->rotspeed))
		- cub->raycast->dir_y * sin(-(cub->raycast->rotspeed));
	cub->raycast->dir_y = cub->raycast->old_dir_x
		* sin(-(cub->raycast->rotspeed))
		+ cub->raycast->dir_y * cos(-(cub->raycast->rotspeed));
	cub->raycast->old_plane_x = cub->raycast->plane_x;
	cub->raycast->plane_x = cub->raycast->plane_x
		* cos(-(cub->raycast->rotspeed))
		- cub->raycast->plane_y * sin(-(cub->raycast->rotspeed));
	cub->raycast->plane_y = cub->raycast->old_plane_x
		* sin(-(cub->raycast->rotspeed)) + cub->raycast->plane_y
		* cos(-(cub->raycast->rotspeed));
}

void	key_look_left(t_info *cub)
{
	cub->raycast->old_dir_x = cub->raycast->dir_x;
	cub->raycast->dir_x = cub->raycast->dir_x * cos(cub->raycast->rotspeed)
		- cub->raycast->dir_y * sin(cub->raycast->rotspeed);
	cub->raycast->dir_y = cub->raycast->old_dir_x * sin(cub->raycast->rotspeed)
		+ cub->raycast->dir_y * cos(cub->raycast->rotspeed);
	cub->raycast->old_plane_x = cub->raycast->plane_x;
	cub->raycast->plane_x = cub->raycast->plane_x * cos(cub->raycast->rotspeed)
		- cub->raycast->plane_y * sin(cub->raycast->rotspeed);
	cub->raycast->plane_y = cub->raycast->old_plane_x
		* sin(cub->raycast->rotspeed)
		+ cub->raycast->plane_y * cos(cub->raycast->rotspeed);
}
