/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:40:22 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 17:18:56 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	cub_init(t_info *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->win = NULL;
	cub->mm = NULL;
	cub->mm_bg = NULL;
	cub->mm_player = NULL;
	cub->mm_wall = NULL;
	cub->minimap = NULL;
	cub->no_img = NULL;
	cub->ea_img = NULL;
	cub->so_img = NULL;
	cub->we_img = NULL;
	cub->full_img = NULL;
}

void	raycast_init(t_rcast *raycast, t_tibs *tibs)
{
	raycast->pos_x = (double)tibs->res_x + 0.5;
	raycast->pos_y = (double)tibs->res_y + 0.5;
	raycast->time = 0;
	raycast->old_time = 0;
	raycast->sidedist_x = 0;
	raycast->sidedist_y = 0;
	raycast->deltadist_x = 0;
	raycast->deltadist_y = 0;
	raycast->perpwalldist = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->hit = 0;
	raycast->side = 0;
	raycast->lineheight = 0;
	raycast->draw_start = 0;
	raycast->draw_end = 0;
	raycast->color = 0;
	raycast->movespeed = 0.2;
	raycast->rotspeed = 0.05;
	raycast->color = 0;
	raycast->dest_color = 0;
}

int	images_data_init(t_info *cub)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	cub->no_add = mlx_get_data_addr(cub->no_img, &pixel_bits, &line_bytes,
			&endian);
	if (!cub->no_add)
		return (0);
	cub->so_add = mlx_get_data_addr(cub->so_img, &pixel_bits, &line_bytes,
			&endian);
	if (!cub->so_add)
		return (0);
	cub->ea_add = mlx_get_data_addr(cub->ea_img, &pixel_bits, &line_bytes,
			&endian);
	if (!cub->ea_add)
		return (0);
	cub->we_add = mlx_get_data_addr(cub->we_img, &pixel_bits, &line_bytes,
			&endian);
	if (!cub->we_add)
		return (0);
	cub->buffer = mlx_get_data_addr(cub->full_img, &pixel_bits, &line_bytes,
			&endian);
	if (!cub->buffer)
		return (0);
	return (1);
}

int	minimap_init(t_info *cub)
{
	int	w;
	int	h;

	cub->mm = mlx_new_image(cub->mlx, 224, 224);
	if (!cub->mm)
		return (0);
	cub->mm_wall = mlx_xpm_file_to_image(cub->mlx, MMWALL, &w, &h);
	if (!cub->mm_wall)
		return (0);
	cub->mm_bg = mlx_xpm_file_to_image(cub->mlx, MMBG, &w, &h);
	if (!cub->mm_bg)
		return (0);
	cub->mm_player = mlx_xpm_file_to_image(cub->mlx, MMPLAY, &w, &h);
	if (!cub->mm_player)
		return (0);
	return (1);
}

int	images_init(t_info *cub)
{
	cub->no_img = mlx_xpm_file_to_image(cub->mlx, cub->tibs->north_path,
			&cub->no_w, &cub->no_h);
	if (!cub->no_img || cub->no_w != TEXTWIDTH || cub->no_h != TEXTHEIGHT)
		return (ft_putstr_fd("Error: north texture\n", 2), 0);
	cub->so_img = mlx_xpm_file_to_image(cub->mlx, cub->tibs->south_path,
			&cub->so_w, &cub->so_h);
	if (!cub->so_img || cub->so_w != TEXTWIDTH || cub->so_h != TEXTHEIGHT)
		return (ft_putstr_fd("Error: south texture\n", 2), 0);
	cub->ea_img = mlx_xpm_file_to_image(cub->mlx, cub->tibs->east_path,
			&cub->ea_w, &cub->ea_h);
	if (!cub->ea_img || cub->ea_w != TEXTWIDTH || cub->ea_h != TEXTHEIGHT)
		return (ft_putstr_fd("Error: east texture\n", 2), 0);
	cub->we_img = mlx_xpm_file_to_image(cub->mlx, cub->tibs->west_path,
			&cub->we_w, &cub->we_h);
	if (!cub->we_img || cub->we_w != TEXTWIDTH || cub->we_h != TEXTHEIGHT)
		return (ft_putstr_fd("Error: west texture\n", 2), 0);
	cub->full_img = mlx_new_image(cub->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!cub->full_img)
		return (0);
	if (!minimap_init(cub))
		return (0);
	return (images_data_init(cub));
}
