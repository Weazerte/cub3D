/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:34 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/14 20:01:53 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void    ft_init_texture(t_tibs *tibs)
{
    tibs->north_texture = NULL;
    tibs->south_texture = NULL;
    tibs->east_texture = NULL;
    tibs->west_texture = NULL;
}

char   *ft_trunc_path(char *path, int j)
{
    char    *tmp;
    int     i;
    int     k;

    i = 0;
    k = j;
    while (path[k])
        k++;
    k--;
    while (path[k] == ' '|| path[k] == '\n' || path[k] == ' ')
        k--;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(path) - j - k + 1));
    while (path[j])
    {
        tmp[i] = path[j];
        i++;
        j++;
    }
    tmp[i] = '\0';
    return (tmp);
}

static char    *ft_find_path(char **map, char first, char scnd)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    while (map[i])
    {
        j = ft_skip_space(map[i]);
        if ((map[i][j] == first && map[i][j + 1] == ' ') || (map[i][j] == first && map[i][j + 1] == scnd))
        {
            while (map[i][j] != ' ')
                j++;
            j += ft_skip_space(map[i] + j);
            tmp = ft_strdup(ft_trunc_path(map[i], j));
            return (tmp);
        }
        j = 0;
        i++;
    }
    return (NULL);
}

int ft_check_texture(char **map, t_tibs *tibs)
{
    char    *tmp;
    int     width;
    int     height;
    
    width = 2128;
    height = 3200;
    // printf("mlx_ptr = %p\n", tibs->mlx_ptr);
    ft_init_texture(tibs);
    tmp = ft_find_path(map, 'N', 'O');
    // printf("tmp = %s\n", tmp);
    tibs->north_texture = mlx_xpm_file_to_image(tibs->mlx_ptr, tmp, &width, &height);
    free(tmp);
    tmp = ft_find_path(map, 'S', 'O');
    // printf("tmp = %s\n", tmp);
    tibs->south_texture = mlx_xpm_file_to_image(tibs->mlx_ptr, tmp, &width, &height);
    free(tmp);
    tmp = ft_find_path(map, 'E', 'A');
    // printf("tmp = %s\n", tmp);
    tibs->east_texture = mlx_xpm_file_to_image(tibs->mlx_ptr, tmp, &width, &height);
    free(tmp); 
    tmp = ft_find_path(map, 'W', 'E');
    // printf("tmp = %s\n", tmp);
    tibs->west_texture = mlx_xpm_file_to_image(tibs->mlx_ptr, tmp, &width, &height);
    free(tmp);

    // printf("north_texture = %p\n", tibs->north_texture);
    if (tibs->north_texture == NULL || tibs->south_texture == NULL ||
        tibs->east_texture == NULL || tibs->west_texture == NULL)
    {
        printf("Error missing texture\n");
        return (1);
    }
    return (0);
}
