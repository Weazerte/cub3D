/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:24 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/14 20:09:18 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

//check if the map file is valid (.cub)
int ft_check_name(char *name)
{
    int i;

    i = 0;
    while (name[i])
        i++;
    if (name[i - 1] != 'b' || name[i - 2] != 'u' || name[i - 3] != 'c' || name[i - 4] != '.')
        return (1);
    return (0);
}

// static void    ft_print_map(char **map)
// {
//     int i;

//     i = 0;
//     while (map[i])
//     {
//         printf("%s", map[i]);
//         i++;
//     }
//     printf("\n");
// }

int main(int ac, char **av)
{
    char **map;
    char **map_4_test;
    t_tibs *tibs;

    if (ac == 2)
    {
        if (ft_check_name(av[1]) == 1)
        {
            // printf("Error Invalid file name\n");
            return (1);
        }
        map = ft_fill_map(av[1]);
        if (map == NULL)
            return (1);
        tibs = malloc(sizeof(t_tibs));
        if (tibs == NULL)
        {
            // printf("Error malloc\n");
            ft_free_map(map);
            return (1);
        }
        tibs->map = ft_map_dup(map);
        map_4_test = ft_map_dup(map);
        tibs->direction = ft_wich_direction(map_4_test);
        tibs->mlx_ptr = mlx_init();

        
        if (ft_check_spawn(map_4_test) == 1)
        {
            // printf("Error Invalid spawn\n");
            ft_free_pars(tibs, map, map_4_test);
            return (1);
        }
        
        
        if (ft_check_outline(map_4_test, tibs->direction) == 1)
        {
            // printf("Error Invalid map\n");
            ft_free_pars(tibs, map ,map_4_test);
            return (1);
        }
        
        if (ft_check_texture(map, tibs) == 1)
        {
            ft_free_pars(tibs, map ,map_4_test);
            return (1);
        }

        // printf("map valide\n");
        ft_free_mlx(tibs);
        ft_free_pars(tibs, map ,map_4_test);
    }
    return (0);
}

//find texture  : reste le \n a la fin du path, enelever en modifiant le strdup 
// recuperer le rgb
//leak
