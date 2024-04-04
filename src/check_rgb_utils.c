/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:05 by eaubry            #+#    #+#             */
/*   Updated: 2024/03/25 16:36:57 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_check_coma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (0);
}

int	ft_check_tab(int *tab)
{
	int	i;

	i = 1;
	while (tab[i] != -1)
	{
		if (tab[i] <= tab[i - 1])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_will_isdigit(char *str, int i)
{
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (str[j] && j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	ft_replace_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		map[i][j] = ' ';
		j++;
	}
}

void	ft_replace_start(char **map, int x, int y)
{
	if (map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'E'
		|| map[x][y] == 'W')
		map[x][y] = '0';
}
