/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:32 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 17:18:11 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	free_minimap(t_info *cub)
{
	int	i;

	i = 0;
	if (cub->minimap)
	{
		while (i < cub->max_rows + 4)
		{
			free(cub->minimap[i]);
			i++;
		}
		free(cub->minimap);
	}
	return (0);
}

int	free_imgs(t_info *cub)
{
	if (cub->minimap)
		free_minimap(cub);
	if (cub->no_img)
		mlx_destroy_image(cub->mlx, cub->no_img);
	if (cub->so_img)
		mlx_destroy_image(cub->mlx, cub->so_img);
	if (cub->ea_img)
		mlx_destroy_image(cub->mlx, cub->ea_img);
	if (cub->we_img)
		mlx_destroy_image(cub->mlx, cub->we_img);
	if (cub->full_img)
		mlx_destroy_image(cub->mlx, cub->full_img);
	if (cub->mm)
		mlx_destroy_image(cub->mlx, cub->mm);
	if (cub->mm_wall)
		mlx_destroy_image(cub->mlx, cub->mm_wall);
	if (cub->mm_bg)
		mlx_destroy_image(cub->mlx, cub->mm_bg);
	if (cub->mm_player)
		mlx_destroy_image(cub->mlx, cub->mm_player);
	return (0);
}

int	ft_free_all(t_info *cub)
{
	free_imgs(cub);
	if (cub->mlx && cub->win)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
	}
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	if (cub->tibs)
		ft_free_tibs(cub->tibs);
	exit(0);
}
