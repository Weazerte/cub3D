/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:50:59 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 12:27:13 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	fill_duplicate(t_info *cub, char **minimap)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->max_rows)
	{
		j = 0;
		while (j < cub->max_len)
		{
			if (cub->tibs->map[i][j] && cub->tibs->map[i][j] == '1')
				minimap[i + 2][j + 2] = '1';
			j++;
			if (!cub->tibs->map[i][j])
				while (j < cub->max_len)
					minimap[i + 2][j++ + 2] = '0';
		}
		i++;
	}
}

char	**duplicate_minimap(t_info *cub)
{
	char	**minimap;
	int		i;
	int		j;

	minimap = NULL;
	cub->max_rows = get_max_rows(cub->tibs->map);
	cub->max_len = get_max_len(cub->tibs->map);
	minimap = (char **)malloc(sizeof(char *) * (cub->max_rows + 4 + 1));
	if (!minimap)
		return (NULL);
	i = 0;
	while (i < cub->max_rows + 4)
	{
		j = 0;
		minimap[i] = (char *)malloc(sizeof(char) * (cub->max_len + 4 + 1));
		while (j < cub->max_len + 4)
		{
			minimap[i][j] = '0';
			j++;
		}
		minimap[i][j] = '\0';
		i++;
	}
	fill_duplicate(cub, minimap);
	return (minimap);
}

void	put_minimap_to_img(char **minimap, t_info *cub)
{
	int	col;
	int	row;

	row = 0;
	while (row < 7)
	{
		col = 0;
		while (col < 7)
		{
			if (row == 3 && col == 3)
				mlx_put_image_to_window(cub->mlx, cub->win, cub->mm_player,
					3 * MINIMAPSIZE, 3 * MINIMAPSIZE);
			else if (minimap[(int)cub->raycast->pos_x - 3 + col + 2]
				[(int)cub->raycast->pos_y - 3 + row + 2] == '1')
				mlx_put_image_to_window(cub->mlx, cub->win, cub->mm_wall,
					row * MINIMAPSIZE, col * MINIMAPSIZE);
			else
				mlx_put_image_to_window(cub->mlx, cub->win, cub->mm_bg,
					row * MINIMAPSIZE, col * MINIMAPSIZE);
			col++;
		}
		row++;
	}
}

int	create_minimap_img(t_info *cub)
{
	cub->minimap = duplicate_minimap(cub);
	if (!cub->minimap)
		return (0);
	put_minimap_to_img(cub->minimap, cub);
	return (1);
}
