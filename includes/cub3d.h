/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/05 16:54:21 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "ads_gfx.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define DEG_VERTICAL_FOV 86.3

// unités de distance par sec
# define TRANS_SPEED 1.4
// radians par seconde
# define ROT_SPEED 1.4

# define MAP_DEFAULT_FNAME "assets/maps/map_subject.cub"
# define MAP_TAG_NORTH_TEXTURE "NO"
# define MAP_TAG_SOUTH_TEXTURE "SO"
# define MAP_TAG_WEST_TEXTURE "WE"
# define MAP_TAG_EAST_TEXTURE "EA"
# define MAP_TAG_CEIL_COLOR "C"
# define MAP_TAG_FLOOR_COLOR "F"

//# define NORTH_ANGLE M_PI_2
# define NORTH_ANGLE 1.57079632679489661923
//# define SOUTH_ANGLE (3.0 * M_PI_2)
# define SOUTH_ANGLE 4.71238898038468985769
//# define WEST_ANGLE M_PI
# define WEST_ANGLE 3.14159265358979323846
# define EAST_ANGLE 0.0

typedef enum e_directions
{
	East,
	North,
	West,
	South
}					t_directions;

typedef enum e_keys
{
	k_fire_1 = XK_Control_L,
	k_fire_2 = XK_Control_R,
	k_open_1 = XK_space,
	k_open_2 = XK_q,
	k_up_1 = XK_Up,
	k_up_2 = XK_w,
	k_down_1 = XK_Down,
	k_down_2 = XK_s,
	k_left_1 = XK_Left,
	k_left_2 = XK_a,
	k_right_1 = XK_Right,
	k_right_2 = XK_d,
	k_strafe_alt = XK_Alt_L,
	k_strafe_switch = XK_F10,
	k_run = XK_Shift_L
}					t_keys;

typedef enum e_page
{
	LANDING_PAGE,
	GAME_PAGE,
	EXIT_PAGE
}					t_page;

typedef enum e_error
{
	NO_ERROR,
	MULTIPLE_PLAYER,
	NO_PLAYER,
	NO_MAP,
	NO_TEXTURE,
	NO_COLOR,
	INVALID_CHAR,
}					t_error;

typedef enum e_door_state
{
	NO_DOOR,
	DOOR_CLOSED,
	DOOR_OPENED,
}					t_door_state;

typedef struct s_player_inputs
{
	bool			open;
	bool			run;
	bool			mv_forward;
	bool			mv_backward;
	bool			mv_left;
	bool			mv_right;
	bool			turn_left;
	bool			turn_right;
	int				mouse_x;
	int				mouse_y;
	bool			strafe_mode;
	bool			strafe_alt;
	bool			k_fire_1;
	bool			k_fire_2;
	bool			k_open_1;
	bool			k_open_2;
	bool			k_up_1;
	bool			k_up_2;
	bool			k_down_1;
	bool			k_down_2;
	bool			k_left_1;
	bool			k_left_2;
	bool			k_right_1;
	bool			k_right_2;
	bool			k_run;
}					t_player_inputs;

/* type t_image is defined in ads_gfx.h
typedef struct s_image
{
	union
	{
		void		*ptr;
		t_img		*_img;
	};
	char			*pixels;
	int				bpp;
	int				line_size;
	int				endian;
	t_point			pos;
	t_size2i		dim;
}					t_image;
*/

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			mlx_img;
	t_image			text_north;
	t_image			text_south;
	t_image			text_west;
	t_image			text_east;
	int				color_floor;
	int				color_ceil;
	// 'pixel' array seems useless, we can use 'mlx_img.pixels'
	// from mlx_get_data_addr()
	int				**pixel;
}					t_mlx;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_player
{
	// position
	t_pointd		pos;
	// direction: angle in radians
	// East: 0, North: pi/2, West: pi, South: 3pi/2 (-> trigo circle logic)
	double			dir;
	// vertical field of view (radians)
	double			vertical_fov;
}					t_player;

typedef struct s_map
{
	char			**m;
	int				height;
	int				width;
	char			*north_tfname;
	char			*south_tfname;
	char			*west_tfname;
	char			*east_tfname;
	t_color			col_floor;
	t_color			col_ceil;
	double			wall_heightscale;
	t_error			error;
}					t_map;

typedef struct s_game
{
	// temps de calcul de la dernière frame en seconde
	double			frame_time;
	struct timeval	last_time;
	t_page			page;
}					t_game;

typedef struct s_cub3d
{
	t_player		player;
	t_mlx			mlx;
	t_map			map;
	t_game			game;
	t_player_inputs	inputs;
}					t_cub3d;

/*typedef enum e_looking_dir
{
	look_up,
	look_down,
	look_left,
	look_right,
}	t_looking_dir*/

typedef struct s_raycast
{
	// image column to render
	int				column;
	// ray angle
	double			angle;

	// point d'intersection avec la prochaine verticale
	t_pointd		v_inter;
	// incréments sur les axes x et y entre 2 intersections verticales
	t_size2d		v_inc;
	// distance à la prochaine intersection verticale
	double			v_dist;
	// distance entre deux intersections verticales
	double			v_dist_inc;

	// point d'intersection avec la prochaine horizontale
	t_pointd		h_inter;
	// incréments sur les axes x et y entre 2 intersections horizontales
	t_size2d		h_inc;
	// distance à la prochaine intersection horizontale
	double			h_dist;
	// distance entre deux intersections horizontales
	double			h_dist_inc;
}					t_raycast;

int					parse_cub3d(char *filename, t_cub3d *cub);
bool				begin_with_tag(char *line, char *tag);
bool				get_tag_value(char *line, char *tag, char **value);
bool				is_map(char *line);
int					parse_map(t_cub3d *cub3d, int fd, char *line);
int					find_map_size(int fd, t_cub3d *cub3d);
int					parse_texture(char *line, t_cub3d *cub3d);
void				parse_color(char *line, t_cub3d *cub3d);
void				init_parsing(t_cub3d *cub3d);
void				free_parsing(t_map *map);
void				print_parsing(t_cub3d *cub3d);
bool				is_texture(char *line);
bool				is_color(char *line);
int					check_parsing(t_cub3d *cub3d);

int					mlx_init_data(t_cub3d *cub3d);
int					mlx_start(t_cub3d *cub3d);
int					mlx_close(t_mlx *mlx);
int					mlx_create_img(t_cub3d *cub3d);
int					mlx_looping(t_cub3d *cub3d);
int					ft_reset_img(t_cub3d *cub3d);
int					ft_free_img(t_mlx *mlx);
int					ft_init_img(t_cub3d *cub3d);
void				img_pix_put(t_image *img, t_uint x, t_uint y, int color);
int					ft_close(t_cub3d *cub3d, char *errmsg);
int					ft_close_cr(t_cub3d *cub3d);

void				render_frame(t_cub3d *cub);

int					render(t_cub3d *cub3d);
int					render_landing_page(t_cub3d *cub3d);
int					render_game_page(t_cub3d *cub3d);
void				update_n_draw_fps(t_cub3d *cub3d);
int					render_exit_page(t_cub3d *cub3d);

// void			render_background(t_cub3d *cub3d, int color);

int					key_press(int keycode, t_cub3d *cub3d);
int					key_release(int keycode, t_cub3d *cub3d);
int					init_keys(t_cub3d *cub3d);
void				mouse_move(t_cub3d *cub3d);

int					draw_minimap(t_cub3d *cub3d);

int					update_player_pos(t_cub3d *cub3d);
void				rotate_player(t_player *p, double angle);
double				angles_add(double alpha, double beta);

t_pointd			collides_wall(t_cub3d *cub, t_pointd old_pos);
int					interact_door(t_cub3d *cub, t_pointd pos);

t_directions		get_wall_orientation(double ray_angle, bool vertical_wall);
int					get_wall_color(t_directions orientation, double distance,
					int wallitem);
void				draw_floor_n_ceil(t_cub3d *c);

#endif