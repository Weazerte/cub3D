/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:46 by thenry            #+#    #+#             */
/*   Updated: 2024/03/20 15:53:22 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	raycast_one(t_rcast *raycast, int x)
{
	raycast->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	raycast->raydir_x = raycast->dir_x + raycast->plane_x * raycast->camera_x;
	raycast->raydir_y = raycast->dir_y + raycast->plane_y * raycast->camera_x;
	raycast->map_x = (int)raycast->pos_x;
	raycast->map_y = (int)raycast->pos_y;
	if (raycast->raydir_x == 0)
		raycast->deltadist_x = 1e30;
	else
		raycast->deltadist_x = fabs(1 / raycast->raydir_x);
	if (raycast->raydir_y == 0)
		raycast->deltadist_y = 1e30;
	else
		raycast->deltadist_y = fabs(1 / raycast->raydir_y);
}

void	raycast_two(t_rcast *raycast)
{
	if (raycast->raydir_x < 0)
	{
		raycast->step_x = -1;
		raycast->sidedist_x = (raycast->pos_x - raycast->map_x)
			* raycast->deltadist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->sidedist_x = (raycast->map_x + 1 - raycast->pos_x)
			* raycast->deltadist_x;
	}
	if (raycast->raydir_y < 0)
	{
		raycast->step_y = -1;
		raycast->sidedist_y = (raycast->pos_y - raycast->map_y)
			* raycast->deltadist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->sidedist_y = (raycast->map_y + 1 - raycast->pos_y)
			* raycast->deltadist_y;
	}
}

// Digital Differential Analysis Algo
void	dda_algo(t_rcast *raycast, t_tibs *tibs)
{
	while (raycast->hit == 0)
	{
		if (raycast->sidedist_x < raycast->sidedist_y)
		{
			raycast->sidedist_x += raycast->deltadist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->sidedist_y += raycast->deltadist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (tibs->map[raycast->map_x][raycast->map_y] == '1')
			raycast->hit = 1;
	}
}

void	raycast_three(t_rcast *raycast)
{
	if (raycast->side == 0)
		raycast->perpwalldist = (raycast->sidedist_x - raycast->deltadist_x);
	else
		raycast->perpwalldist = (raycast->sidedist_y - raycast->deltadist_y);
	raycast->lineheight = (int)(SCREENHEIGHT / raycast->perpwalldist);
	raycast->draw_start = -raycast->lineheight / 2 + SCREENHEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->lineheight / 2 + SCREENHEIGHT / 2;
	if (raycast->draw_end >= SCREENHEIGHT)
		raycast->draw_end = SCREENHEIGHT - 1;
	if (raycast->side == 0)
		raycast->wall_x = raycast->pos_y + raycast->perpwalldist
			* raycast->raydir_y;
	else
		raycast->wall_x = raycast->pos_x + raycast->perpwalldist
			* raycast->raydir_x;
	raycast->wall_x -= floor(raycast->wall_x);
}

void	raycast_four(t_rcast *raycast, t_info *cub)
{
	raycast->text_x = raycast->wall_x * (double)TEXTWIDTH;
	if (raycast->side == 0 && raycast->raydir_x > 0)
		raycast->text_x = cub->ea_w - raycast->text_x - 1;
	else if (raycast->side == 1 && raycast->raydir_y < 0)
		raycast->text_x = cub->no_w - raycast->text_x - 1;
	else if (raycast->side == 0 && raycast->raydir_x < 0)
		raycast->text_x = cub->we_w - raycast->text_x - 1;
	else if (raycast->side == 1 && raycast->raydir_y > 0)
		raycast->text_x = cub->so_w - raycast->text_x - 1;
	raycast->step = 1.0 * TEXTHEIGHT / raycast->lineheight;
	raycast->text_pos = (raycast->draw_start - SCREENHEIGHT / 2
			+ raycast->lineheight / 2) * raycast->step;
}
