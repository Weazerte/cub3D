/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:34 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/20 19:19:45 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

char	*ft_trunc_path(char *path)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (path[j])
	{
		if (path[j] == '\n' || path[j] == ' ')
			break ;
		j++;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	if (tmp == NULL)
		return (NULL);
	while (path[j])
	{
		if (path[j] == '\n')
			return (tmp[i] = '\0', tmp);
		tmp[i] = path[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_find_path(char **map, char first, char scnd, int *pos)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		if ((map[i][j] == first && map[i][j + 1] == ' ') || (map[i][j] == first
				&& map[i][j + 1] == scnd))
		{
			*pos = i;
			while (map[i][j] != ' ')
				j++;
			j += ft_skip_space(map[i] + j);
			tmp = ft_trunc_path(map[i] + j);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int	ft_check_texture(char **map, t_tibs *tibs)
{
	char	*tmp;
	int i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * 7);
	tmp = ft_find_path(map, 'N', 'O', &i);
	tab[0] = i;
	tibs->north_path = tmp;
	tmp = ft_find_path(map, 'S', 'O', &i);
	tab[1] = i;
	tibs->south_path = tmp;
	tmp = ft_find_path(map, 'E', 'A', &i);
	tab[2] = i;
	tibs->east_path = tmp;
	tmp = ft_find_path(map, 'W', 'E', &i);
	tab[3] = i;
	tibs->west_path = tmp;
	if (ft_check_rgb_floor(&tibs->floor, map, &tab) == 1)
		return (1);
	if (ft_check_rgb_ceiling(&tibs->ceiling, map, tab) == 1)
		return (1);
	if (tibs->north_path == NULL || tibs->south_path == NULL
		|| tibs->east_path == NULL || tibs->west_path == NULL)
		return (ft_printf("Error missing texture\n"), 1);
	return (0);
}
