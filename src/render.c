/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:46:19 by thenry            #+#    #+#             */
/*   Updated: 2024/03/21 18:31:44 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

void	put_pixel_to_full_img(t_info *cub, int x, int y, int color)
{
	char	*tmp;
	int		pix;

	pix = (y * (SCREENWIDTH * 4)) + (x * 4);
	tmp = cub->buffer + pix;
	*(int *)tmp = color;
}

void	color_text(t_info *cub, int x, int y)
{
	cub->raycast->text_y = ((int)cub->raycast->text_pos) & (TEXTHEIGHT - 1);
	cub->raycast->text_pos += cub->raycast->step;
	if (cub->raycast->side == 0)
	{
		if (cub->raycast->raydir_x < 0)
			cub->raycast->color = ((int *)cub->no_add)[(int)(TEXTWIDTH
					* cub->raycast->text_y + cub->raycast->text_x)];
		else
			cub->raycast->color = ((int *)cub->so_add)[(int)(TEXTWIDTH
					* cub->raycast->text_y + cub->raycast->text_x)];
	}
	else
	{
		if (cub->raycast->raydir_y > 0)
			cub->raycast->color = ((int *)cub->ea_add)[(int)(TEXTWIDTH
					* cub->raycast->text_y + cub->raycast->text_x)];
		else
			cub->raycast->color = ((int *)cub->we_add)[(int)(TEXTWIDTH
					* cub->raycast->text_y + cub->raycast->text_x)];
	}
	put_pixel_to_full_img(cub, x, y, cub->raycast->color);
}

void	color_switch(t_info *cub, int x)
{
	int	y;

	y = 0;
	while (y++ < cub->raycast->draw_start)
		put_pixel_to_full_img(cub, x, y, cub->tibs->ceiling);
	while (y++ < cub->raycast->draw_end)
		color_text(cub, x, y);
	while (y++ < SCREENHEIGHT)
		put_pixel_to_full_img(cub, x, y, cub->tibs->floor);
}
