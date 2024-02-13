/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:40:59 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/13 17:32:11 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

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

int   ft_find_map_start_j(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = ft_skip_space(map[i]);
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}

int   ft_find_map_start_i(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = ft_skip_space(map[i]);
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                return (i);
            j++;
        }
        i++;
    }
    return (-1);
}

int ft_check_after_flood(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '2')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void	ft_flood_fill(char **map, char c, int x, int y)
{
    // printf("x = %d\ny = %d\n", x, y);
	if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] == c)
		map[x][y] = '2';
	if (map[x][y] == '1' || map[x][y] == '2')
        return ;
    map[x][y] = '1';
	ft_flood_fill(map, c, x + 1, y);
	ft_flood_fill(map, c, x - 1, y);
	ft_flood_fill(map, c, x, y + 1);
	ft_flood_fill(map, c, x, y - 1);
}

// flood fill to check if the map is closed
int ft_check_outline(char **map, char c)
{
    int x;
    int y;
    
    x = ft_find_map_start_i(map);
    y = ft_find_map_start_j(map);
    ft_flood_fill(map, c, x, y);
    // ft_print_map(map);
    return (ft_check_after_flood(map));
}