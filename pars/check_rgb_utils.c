/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:05 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/20 19:20:14 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int ft_check_coma(t_rgb *rgb, char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
    {
        rgb->r = -1;
        rgb->g = -1;
        rgb->b = -1;
        return (1);
    }
    return (0);
}

int ft_check_tab(int *tab)
{
    int i;
    
    i = 1;
    while (tab[i] != -1)
    {
        if (tab[i] <= tab[i - 1])
            return (1);
        i++;
    }
    return (0);
}
