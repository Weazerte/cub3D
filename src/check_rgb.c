/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:13:47 by eaubry            #+#    #+#             */
/*   Updated: 2024/03/25 16:15:47 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/pars.h"

long long int	ft_atoi_4_rgb(char *nptr)
{
	size_t			i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr == NULL)
		return (-1);
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_find_rbg(char *str)
{
	int		i;
	char	*tmp;
	int		res;

	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	tmp = ft_will_isdigit(str, i);
	if (ft_atoi_4_rgb(tmp) < 0 || ft_atoi_4_rgb(tmp) > 255)
	{
		free(tmp);
		return (ft_putstr_fd("Error Invalid floor color\n", 2), -1);
	}
	res = ft_atoi_4_rgb(tmp);
	free(tmp);
	return (res);
}

int	ft_find_convert(char *str)
{
	int		i;
	int		j;
	int		rgb[3];

	if (ft_check_coma(str) == -1)
		return (-1);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			rgb[j] = ft_find_rbg(str + i);
			if (rgb[j] == -1)
				return (-1);
			j++;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			rgb[j++] = -1;
	}
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
		return (-1);
	return (rgb[0] * 65536 + rgb[1] * 256 + rgb[2]);
}

int	ft_check_rgb_floor(char **map)
{
	int	k;
	int	j;
	int	res;

	k = -1;
	while (map[++k])
	{
		j = ft_skip_space(map[k]);
		if (map[k][j] == 'F')
		{
			j++;
			j += ft_skip_space(map[k] + j);
			if (ft_isdigit(map[k][j]) == 1)
				return (ft_putstr_fd("Error Invalid floor color\n", 2), 1);
			res = ft_find_convert(map[k] + j);
			ft_replace_line(map, k);
			return (res);
		}
	}
	return (-1);
}

int	ft_check_rgb_ceiling(char **map)
{
	int	k;
	int	j;
	int	res;

	k = -1;
	while (map[++k])
	{
		j = ft_skip_space(map[k]);
		if (map[k][j] == 'C')
		{
			j++;
			j += ft_skip_space(map[k] + j);
			if (ft_isdigit(map[k][j]) == 1)
				return (ft_putstr_fd("Error Invalid floor color\n", 2), 1);
			res = ft_find_convert(map[k] + j);
			ft_replace_line(map, k);
			return (res);
		}
	}
	return (-1);
}
