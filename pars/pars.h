/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weaz <weaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:58:18 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/22 00:46:59 by weaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H

# define PARS_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
// #include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_tibs
{
	char	**map;
	t_rgb	floor;
	t_rgb	ceiling;
	char	direction;
	char	*north_path;
	;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}			t_tibs;

int			ft_pars(t_tibs *tibs, char **av);
char		**ft_map_dup(char **map);
int			ft_skip_space(char *str);
int			ft_check_outline(char **map, char c);
int			ft_check_spawn(char **map);
char		**ft_fill_map(char *map_name);
void		ft_free_pars(t_tibs *tibs, char **map, char **map2);
void		ft_free_map(char **map);
void		ft_free_tibs(t_tibs *tibs);
char		ft_wich_direction(char **map);
int			ft_check_texture(char **map, t_tibs *tibs);
void		ft_free_mlx(t_tibs *tibs);
void		ft_memdel(void **ptr);
int			ft_check_rgb_ceiling(t_rgb *rgb, char **map);
int			ft_check_rgb_floor(t_rgb *rgb, char **map);
int			ft_check_coma(t_rgb *rgb, char *str);
int			ft_check_tab(int *tab);

#endif