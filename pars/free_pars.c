/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:58:01 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/13 17:33:54 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void    ft_free_tibs(t_tibs *tibs)
{
    int i;

    i = 0;
    while (tibs->map[i])
    {
        free(tibs->map[i]);
        i++;
    }
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
            printf("map[%d] = %s\n", i, map[i]);
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
