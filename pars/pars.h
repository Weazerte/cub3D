/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:58:18 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/13 17:24:56 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H

# define PARS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line/get_next_line.h"

typedef struct s_rgb
{
    int r;
    int g;
    int b;
}               t_rgb;

typedef struct s_tibs
{
    char **map;
    t_rgb *rgb;
    char    direction;
    void   *north_texture;;
    void   *south_texture;
    void   *east_texture;
    void   *west_texture;
}              t_tibs;

char    **ft_map_dup(char **map);
int     ft_skip_space(char *str);
int     ft_check_outline(char **map, char  c);
int     ft_check_spawn(char **map);
char    **ft_fill_map(char *map_name);
void    ft_free_pars(t_tibs *tibs, char **map , char **map2);
void    ft_free_map(char **map);
char    ft_wich_direction(char **map);

#endif