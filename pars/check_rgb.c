/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:13:47 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/20 19:18:32 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

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
	if (nptr)
		free(nptr);
	return (sign * result);
}

char	*ft_will_isdigit(char *str, int i)
{
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (str[j] && j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	ft_fill_rgb(t_rgb *rgb, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_isdigit(str[i]) == 0)
	{
		if (ft_check_coma(rgb, str) == 1)
			return ;
		while (str[j] != ',')
			j++;
		rgb->r = ft_atoi_4_rgb(ft_will_isdigit(str, j));
		j++;
		i = j;
		while (str[j] != ',')
			j++;
		rgb->g = ft_atoi_4_rgb(ft_will_isdigit(str + i, j - i));
		j++;
		i = j;
		while (ft_isdigit(str[j]) == 0)
			j++;
		rgb->b = ft_atoi_4_rgb(ft_will_isdigit(str + i, j - i));
	}
	return ;
}

int	ft_check_rgb_floor(t_rgb *rgb, char **map, int **tab)
{
	int	i;
	int	j;

	i = 0;
	*tab[6] = -1;
	while (map[i])
	{
		j = ft_skip_space(map[i]);
		if (map[i][j] == 'F')
		{
			*tab[4] = i;
			j++;
			j += ft_skip_space(map[i] + j);
			if (ft_isdigit(map[i][j]) == 1)
				return (ft_printf("Error Invalid floor color\n"), 1);
			ft_fill_rgb(rgb, map[i] + j);
		}
		i++;
	}
	if ((rgb->b < 0 || rgb->b > 255) || (rgb->g < 0 || rgb->g > 255)
		|| (rgb->r < 0 || rgb->r > 255))
		return (ft_printf("Error Invalid floor color\n"), 1);
	return (0);
}

int	ft_check_rgb_ceiling(t_rgb *rgb, char **map, int *tab)
{
	int	i;
	int	j;

	i = 0;

	while (map[i])
	{
		j = ft_skip_space(map[i]);
		if (map[i][j] == 'C')
		{
			tab[5] = i;
			j++;
			j += ft_skip_space(map[i] + j);
			if (ft_isdigit(map[i][j]) == 1)
				return (printf("Error Invalid ceiling color\n"), 1);
			ft_fill_rgb(rgb, map[i] + j);
		}
		i++;
	}
	if (ft_check_tab(tab) == 1)
		return (printf("Error Invalid texture/rgb order\n"), 1);
	if ((rgb->b < 0 || rgb->b > 255) || (rgb->g < 0 || rgb->g > 255)
		|| (rgb->r < 0 || rgb->r > 255))
		return (printf("Error Invalid ceiling color\n"), 1);
	return (0);
}
