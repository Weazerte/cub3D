/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:06:09 by thenry            #+#    #+#             */
/*   Updated: 2024/03/21 18:31:38 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	render(t_info *cub)
{
	int		x;
	t_rcast	*raycast;

	x = 0;
	raycast = cub->raycast;
	while (x < SCREENWIDTH)
	{
		raycast_one(raycast, x);
		raycast_two(raycast);
		dda_algo(raycast, cub->tibs);
		raycast_three(raycast);
		raycast_four(raycast, cub);
		color_switch(cub, x);
		raycast->hit = 0;
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->full_img, 0, 0);
	put_minimap_to_img(cub->minimap, cub);
	return (0);
}

int	launch_cub3d(t_tibs *tibs)
{
	t_info	cub;
	t_rcast	raycast;

	cub.tibs = tibs;
	cub.raycast = &raycast;
	cub_init(&cub);
	raycast_init(cub.raycast, cub.tibs);
	init_dir(cub.raycast, cub.tibs);
	init_plane(cub.raycast, cub.tibs);
	cub.mlx = mlx_init(&cub);
	if (!cub.mlx)
		return (ft_free_all(&cub));
	if (!images_init(&cub))
		return (ft_free_all(&cub));
	cub.win = mlx_new_window(cub.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	if (!cub.win)
		return (ft_free_all(&cub));
	if (!create_minimap_img(&cub))
		return (ft_free_all(&cub));
	mlx_key_hook(cub.win, f_key_hook, &cub);
	mlx_hook(cub.win, DestroyNotify, KeyPressMask, ft_free_all, &cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_tibs	tibs;

	if (ac == 2)
	{
		if (ft_pars(&tibs, av) == 1)
			return (EXIT_FAILURE);
		launch_cub3d(&tibs);
	}
	return (EXIT_SUCCESS);
}
