/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:08:01 by thenry            #+#    #+#             */
/*   Updated: 2024/03/28 18:07:47 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "pars.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define SCREENWIDTH 1920
# define SCREENHEIGHT 1080

# define MAPWIDTH 24
# define MAPHEIGHT 24

# define TEXTWIDTH 64
# define TEXTHEIGHT 64
# define MINIMAPSIZE 32
# define MMWALL "./textures/wall.xpm"
# define MMBG "./textures/bbg.xpm"
# define MMPLAY "./textures/player.xpm"

# define RED 0xFF0000
# define GREEN 0x008000
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define PINK 0xFFC0CB

struct	s_rcast;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*full_img;
	char			*buffer;
	int				height;
	int				width;

	void			*mm;
	void			*mm_wall;
	void			*mm_bg;
	void			*mm_player;

	char			**minimap;
	int				max_rows;
	int				max_len;

	void			*no_img;
	void			*so_img;
	void			*ea_img;
	void			*we_img;

	char			*no_add;
	char			*so_add;
	char			*ea_add;
	char			*we_add;

	int				no_w;
	int				no_h;
	int				so_w;
	int				so_h;
	int				ea_w;
	int				ea_h;
	int				we_w;
	int				we_h;

	struct s_rcast	*raycast;
	struct s_tibs	*tibs;
}					t_info;

typedef struct s_rcast
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				draw_start;
	int				draw_end;
	int				color;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			old_dir_x;
	double			old_dir_y;
	double			old_plane_x;
	double			old_plane_y;
	double			wall_x;
	double			text_x;
	double			text_y;
	double			text_pos;
	double			step;
	int				pixel;
	char			*dest_color;
}					t_rcast;

void				key_look_right(t_info *cub);
void				key_look_left(t_info *cub);

void				key_go_right(t_info *cub);
void				key_go_left(t_info *cub);
void				key_go_up(t_info *cub);
void				key_go_down(t_info *cub);
int					f_key_hook(int keycode, t_info *cub);

int					free_minimap(t_info *cub);
int					free_imgs(t_info *cub);
int					ft_free_all(t_info *cub);

void				init_dir(t_rcast *raycast, t_tibs *tibs);
void				init_plane(t_rcast *raycast, t_tibs *tibs);

void				cub_init(t_info *cub);
void				raycast_init(t_rcast *raycast, t_tibs *tibs);
int					images_data_init(t_info *cub);
int					minimap_init(t_info *cub);
int					images_init(t_info *cub);

void				put_pixel_to_full_img(t_info *cub, int x, int y, int color);
void				color_text(t_info *cub, int x, int y);
void				color_switch(t_info *cub, int x);

void				raycast_one(t_rcast *raycast, int x);
void				raycast_two(t_rcast *raycast);
void				dda_algo(t_rcast *raycast, t_tibs *tibs);
void				raycast_three(t_rcast *raycast);
void				raycast_four(t_rcast *raycast, t_info *cub);

int					render(t_info *cub);
int					launch_cub3d(t_tibs *tibs);

int					get_max_rows(char **map);
int					get_max_len(char **map);

void				fill_duplicate(t_info *cub, char **minimap);
char				**duplicate_minimap(t_info *cub);
void				put_minimap_to_img(char **minimap, t_info *cub);
int					create_minimap_img(t_info *cub);

#endif