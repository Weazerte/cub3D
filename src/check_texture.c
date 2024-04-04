/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:34 by eaubry            #+#    #+#             */
/*   Updated: 2024/03/28 17:33:51 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

int	ft_check_details_utils(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "./", 2) != 0)
		return (1);
	if (ft_strchr(str, ' ') != NULL)
		return (1);
	while (str[++i])
		;
	if (str[i - 1] != 'm' || str[i - 2] != 'p' || str[i - 3] != 'x' || str[i
			- 4] != '.')
		return (1);
	return (0);
}

int	ft_check_details(t_tibs *tibs)
{
	if (ft_check_details_utils(tibs->north_path) == 1)
	{
		ft_putstr_fd("details texture name error\n", 2);
		return (1);
	}
	if (ft_check_details_utils(tibs->south_path) == 1)
	{
		ft_putstr_fd("details texture name error\n", 2);
		return (1);
	}
	if (ft_check_details_utils(tibs->east_path) == 1)
	{
		ft_putstr_fd("details texture name error\n", 2);
		return (1);
	}
	if (ft_check_details_utils(tibs->west_path) == 1)
	{
		ft_putstr_fd("details texture name error\n", 2);
		return (1);
	}
	return (0);
}

char	*ft_trunc_path(char *path)
{
	char	*tmp;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = -1;
	while (path[++size])
		if (path[size] == '\n' || path[size] == ' ')
			break ;
	tmp = malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (j < size)
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

static char	*ft_find_path(char **map, char first, char scnd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		if ((map[i][j] == first && map[i][j + 1] == ' ') || (map[i][j] == first
				&& map[i][j + 1] == scnd && map[i][j + 2] == ' '))
		{
			while (map[i][j] != ' ')
				j++;
			j += ft_skip_space(map[i] + j);
			tmp = ft_trunc_path(map[i] + j);
			ft_replace_line(map, i);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int	ft_check_texture(char **map, t_tibs *tibs)
{
	char	*tmp;

	tmp = ft_find_path(map, 'N', 'O');
	tibs->north_path = tmp;
	tmp = ft_find_path(map, 'S', 'O');
	tibs->south_path = tmp;
	tmp = ft_find_path(map, 'W', 'E');
	tibs->east_path = tmp;
	tmp = ft_find_path(map, 'E', 'A');
	tibs->west_path = tmp;
	if (tibs->north_path == NULL || tibs->south_path == NULL
		|| tibs->east_path == NULL || tibs->west_path == NULL)
		return (ft_putstr_fd("Error missing texture\n", 2), 1);
	if (ft_check_details(tibs) == 1)
		return (ft_putstr_fd("Error textur path\n", 2), 1);
	tibs->floor = ft_check_rgb_floor(map);
	if (tibs->floor == -1)
		return (ft_putstr_fd("Error rgb\n", 2), 1);
	tibs->ceiling = ft_check_rgb_ceiling(map);
	if (tibs->ceiling == -1)
		return (ft_putstr_fd("Error rgb\n", 2), 1);
	return (0);
}
