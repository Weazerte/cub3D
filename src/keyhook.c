/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:39 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 16:40:39 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	key_go_up(t_info *cub)
{
	if (cub->tibs->map[(int)(cub->raycast->pos_x + cub->raycast->dir_x
			* cub->raycast->movespeed)][(int)cub->raycast->pos_y] == '0')
		cub->raycast->pos_x += cub->raycast->dir_x * cub->raycast->movespeed;
	if (cub->tibs->map[(int)cub->raycast->pos_x][(int)(cub->raycast->pos_y
		+ cub->raycast->dir_y * cub->raycast->movespeed)] == '0')
		cub->raycast->pos_y += cub->raycast->dir_y * cub->raycast->movespeed;
}

void	key_go_down(t_info *cub)
{
	if (cub->tibs->map[(int)(cub->raycast->pos_x - cub->raycast->dir_x
			* cub->raycast->movespeed)][(int)cub->raycast->pos_y] == '0')
		cub->raycast->pos_x -= cub->raycast->dir_x * cub->raycast->movespeed;
	if (cub->tibs->map[(int)cub->raycast->pos_x][(int)(cub->raycast->pos_y
		- cub->raycast->dir_y * cub->raycast->movespeed)] == '0')
		cub->raycast->pos_y -= cub->raycast->dir_y * cub->raycast->movespeed;
}

void	key_go_right(t_info *cub)
{
	if (cub->tibs->map[(int)(cub->raycast->pos_x + cub->raycast->dir_y
			* cub->raycast->movespeed)][(int)cub->raycast->pos_y] == '0')
		cub->raycast->pos_x += cub->raycast->dir_y * cub->raycast->movespeed;
	if (cub->tibs->map[(int)(cub->raycast->pos_x)][(int)(cub->raycast->pos_y
		- cub->raycast->dir_x * cub->raycast->movespeed)] == '0')
		cub->raycast->pos_y -= cub->raycast->dir_x * cub->raycast->movespeed;
}

void	key_go_left(t_info *cub)
{
	if (cub->tibs->map[(int)(cub->raycast->pos_x - cub->raycast->dir_y
			* cub->raycast->movespeed)][(int)cub->raycast->pos_y] == '0')
		cub->raycast->pos_x -= cub->raycast->dir_y * cub->raycast->movespeed;
	if (cub->tibs->map[(int)(cub->raycast->pos_x)][(int)(cub->raycast->pos_y
		+ cub->raycast->dir_x * cub->raycast->movespeed)] == '0')
		cub->raycast->pos_y += cub->raycast->dir_x * cub->raycast->movespeed;
}

int	f_key_hook(int keycode, t_info *cub)
{
	if (keycode == XK_d)
		key_go_right(cub);
	if (keycode == XK_a)
		key_go_left(cub);
	if (keycode == XK_Right)
		key_look_right(cub);
	if (keycode == XK_Left)
		key_look_left(cub);
	if (keycode == XK_w || keycode == XK_Up)
		key_go_up(cub);
	if (keycode == XK_s || keycode == XK_Down)
		key_go_down(cub);
	if (keycode == XK_Escape)
		ft_free_all(cub);
	return (0);
}
