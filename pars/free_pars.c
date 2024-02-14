/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:58:01 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/14 20:08:26 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void    ft_free_mlx(t_tibs *tibs)
{
    if (tibs->north_texture)
        mlx_destroy_image(tibs->mlx_ptr, tibs->north_texture);
    if (tibs->south_texture)
        mlx_destroy_image(tibs->mlx_ptr, tibs->south_texture);
    if (tibs->east_texture)
        mlx_destroy_image(tibs->mlx_ptr, tibs->east_texture);
    if (tibs->west_texture)
        mlx_destroy_image(tibs->mlx_ptr, tibs->west_texture);
    if (tibs->mlx_ptr)
    {
        if (tibs->mlx_ptr)
            mlx_destroy_display(tibs->mlx_ptr);
        free(tibs->mlx_ptr);
    }
}

void    ft_free_tibs(t_tibs *tibs)
{
    int i;

    i = 0;
    if (tibs->map)
    {
        while (tibs->map[i])
        {
            if (tibs->map[i])
                free(tibs->map[i]);
            i++;
        }
    }
    if (tibs->map)
        free(tibs->map);
    free(tibs);
}
void    ft_free_map(char **map)
{
    int i;

    i = 0;
    if (map)
    {
        while (map[i])
        {
            if (map[i])
                free(map[i]);
            i++;
        }
    }
    free(map);
}

void    ft_free_pars(t_tibs *tibs, char **map, char **map2)
{
    ft_free_map(map);
    ft_free_map(map2);
    ft_free_tibs(tibs);
}
