/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:52:03 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/13 17:14:11 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int ft_skip_space(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    return (i);
}

int ft_valid_char(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
        return (0);
    return (1);
}

char ft_wich_direction(char **map)
{
    char direction;

    direction = 0;
    while (**map)
    {
        if (**map == 'N' || **map == 'S' || **map == 'E' || **map == 'W')
        {
            direction = **map;
            **map = '0';
        }
        (*map)++;
    }
    return (direction);
}