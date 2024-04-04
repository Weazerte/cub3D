/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:58:18 by eaubry            #+#    #+#             */
/*   Updated: 2024/04/03 15:35:20 by thenry           ###   ########.fr       */
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

typedef struct s_tibs
{
	char	**map;
	int		floor;
	int		ceiling;
	char	direction;
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	int		res_x;
	int		res_y;
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
int			ft_check_rgb_ceiling(char **map);
int			ft_check_rgb_floor(char **map);
int			ft_check_coma(char *str);
int			ft_check_tab(int *tab);
int			ft_find_map_start_i(char **map);
int			ft_find_map_start_j(char **map);
void		ft_replace_start(char **map, int x, int y);
char		*ft_will_isdigit(char *str, int i);
void		ft_replace_line(char **map, int i);
int			ft_strlen_verif(char *str);
int			ft_skip_space2(char *str);
int			ft_check_other_char(char **map);
char		*ft_fill_fisrt_line(void);
int			ft_is_positiv_digit(char c);
int			ft_find_start(char **map);

#endif