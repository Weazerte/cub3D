/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:08 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/13 15:49:09 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int ft_map_size(char *map_name)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        free(line);
    close(fd);
    return (i);
}

char    **ft_fill_map(char *map_name)
{
    int fd;
    char *line;
    char **map;
    int i;

    i = 0;
    map = malloc(sizeof(char *) * ft_map_size(map_name) + 1);
    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        map[i] = ft_strdup(line);
        i++;
        free(line);
        line = get_next_line(fd);
    }
    map[i] = NULL;
    close(fd);
    return (map);
}
