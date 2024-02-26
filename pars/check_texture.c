/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weaz <weaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:34 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/26 14:37:33 by weaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int	ft_check_details_utils(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "./", 2) != 0)
		return (1);
	if (ft_strchr(str, ' ') != NULL)
		return (1);
	while (str[++i]);
	if (str[i - 1] != 'm' || str[i - 2] != 'p' || str[i - 3] != 'x' || str[i - 4] != '.') 
		return (1);
	return (0);
}

int	ft_check_details(t_tibs *tibs)
{
	if (ft_check_details_utils(tibs->north_path) == 1)
	{
		ft_printf("details texture name error\n");
		return (1);
	}
	if (ft_check_details_utils(tibs->south_path) == 1)
	{
		ft_printf("details texture name error\n");
		return (1);
	}
	if (ft_check_details_utils(tibs->east_path) == 1)
	{
		ft_printf("details texture name error\n");
		return (1);
	}
	if (ft_check_details_utils(tibs->west_path) == 1)
	{
		ft_printf("details texture name error\n");
		return (1);
	}
	return (0);
}

char	*ft_trunc_path(char *path)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (path[++j])
	{
		if (path[j] == '\n' || path[j] == ' ')
			break ;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	if (tmp == NULL)
		return (NULL);
	j = 0;
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
			if (i < *pos)
				return (NULL);
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

	i = 0 ;
	tmp = ft_find_path(map, 'N', 'O', &i);
	
	tibs->north_path = tmp;
	tmp = ft_find_path(map, 'S', 'O', &i);
	tibs->south_path = tmp;
	tmp = ft_find_path(map, 'E', 'A', &i);
	tibs->east_path = tmp;
	tmp = ft_find_path(map, 'W', 'E', &i);
	tibs->west_path = tmp;
	if (ft_check_details(tibs) == 1)
		return (ft_printf("Error textur path\n"), 1);
	if (ft_check_rgb_floor(&tibs->floor, map) == 1)
		return (1);
	if (ft_check_rgb_ceiling(&tibs->ceiling, map) == 1)
		return (1);
	if (tibs->north_path == NULL || tibs->south_path == NULL
		|| tibs->east_path == NULL || tibs->west_path == NULL)
		return (ft_printf("Error missing texture\n"), 1);
	return (0);
}
