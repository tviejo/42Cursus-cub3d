/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/28 17:34:09 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "parsing.h"
# include "ads_gfx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.14159265359
# define TRANS_SPEED 0.005
# define ROT_SPEED 0.005

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
	k_strafe_switch = XK_F10
}	t_keys;

typedef enum e_page
{
	LANDING_PAGE,
	GAME_PAGE,
	EXIT_PAGE
}	t_page;

typedef enum e_error
{
	NO_ERROR,
	MULTIPLE_PLAYER,
	NO_PLAYER,
	NO_MAP,
	NO_TEXTURE,
	NO_COLOR,
	INVALID_CHAR,
}	t_error;

typedef struct s_mlx
{
	void		*mlx_img;
	void		*img_north;
	void		*img_south;
	void		*img_west;
	void		*img_east;
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
	void		*mlx_ptr;
	void		*win_ptr;
	// pixel array is useless (to remove), we can use pixels (old name was addr)
	int			**pixel;
}	t_mlx;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}	t_color;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
}	t_player;

typedef struct s_player_inputs
{
	bool		open;
	bool		mv_forward;
	bool		mv_backward;
	bool		mv_left;
	bool		mv_right;
	bool		turn_left;
	bool		turn_right;
	int			mouse_x;
	int			mouse_y;
	bool		strafe_mode;
	bool		strafe_alt;
	bool		k_fire_1;
	bool		k_fire_2;
	bool		k_open_1;
	bool		k_open_2;
	bool		k_up_1;
	bool		k_up_2;
	bool		k_down_1;
	bool		k_down_2;
	bool		k_left_1;
	bool		k_left_2;
	bool		k_right_1;
	bool		k_right_2;
}	t_player_inputs;

typedef struct s_map
{
	char		**m;
	size_t		height;
	size_t		width;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		col_floor;
	t_color		col_ceil;
	t_error		error;
}	t_map;

typedef struct s_game
{
	t_page		page;
}	t_game;
typedef struct s_cub3d
{
	t_player		player;
	t_mlx			mlx;
	t_map			map;
	t_game			game;
	t_player_inputs	inputs;
}	t_cub3d;

int				parse_cub(char *file, t_cub3d *cub3d);
bool			is_map(char *line);
int				parse_map(char *line, int fd, t_cub3d *cub3d);
int				find_map_size(int fd, t_cub3d *cub3d);
void			parse_texture(char *line, t_cub3d *cub3d);
void			parse_color(char *line, t_cub3d *cub3d);
void			init_parsing(t_cub3d *cub3d);
void			free_parsing(t_cub3d *cub3d);
void			print_parsing(t_cub3d *cub3d);
bool			is_texture(char *line);
bool			is_color(char *line);
int				check_parsing(t_cub3d *cub3d);

int				mlx_start(t_cub3d *cub3d);
int				mlx_close(t_cub3d *cub3d);
int				mlx_create_img(t_cub3d *cub3d);
int				mlx_looping(t_cub3d *cub3d);
int				ft_reset_img(t_cub3d *cub3d);
int				ft_free_img(t_cub3d *cub3d);
int				ft_init_img(t_cub3d *cub3d);
int				init_data_mlx(t_cub3d *cub3d);
void			img_pix_put(t_cub3d *cub3d, int x, int y, int color);

int				render(t_cub3d *cub3d);

int				ft_close(t_cub3d *cub3d);

int				render_landing_page(t_cub3d *cub3d);
int				render_game_page(t_cub3d *cub3d);
void			update_n_draw_fps(t_cub3d *cub3d);
int				render_exit_page(t_cub3d *cub3d);

void			render_background(t_cub3d *cub3d, int color);

int				key_press(int keycode, t_cub3d *cub3d);
int				key_release(int keycode, t_cub3d *cub3d);
int				init_keys(t_cub3d *cub3d);
int				mouse_move(int button, int x, int y, t_cub3d *cub3d);

int				draw_minimap(t_cub3d *cub3d);

int				update_player_pos(t_cub3d *cub3d);

#endif
