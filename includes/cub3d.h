/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/08/26 19:49:26 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.1416
# define TRANS_SPEED 0.005
# define ROT_SPEED 0.005

typedef enum e_page
{
	LANDING_PAGE,
	GAME_PAGE,
	EXIT_PAGE
}				t_page;

typedef enum e_error
{
	NO_ERROR,
	MULTPLE_PLAYER,
	NO_PLAYER,
	NO_MAP,
	NO_TEXTURE,
	NO_COLOR,
	INVALID_CHAR,
}			t_error;

typedef struct s_mlx
{
	void		*mlx_img;
	void		*img_north;
	void		*img_south;
	void		*img_west;
	void		*img_east;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*mlx_ptr;
	void		*win_ptr;
	int			**pixel;
}				t_mlx;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
}				t_player;

typedef struct s_keys
{
	bool		open;
    bool		up;
    bool		down;
    bool		left;
    bool		right;
    bool		turn_left;
    bool		turn_right;
	int			mouse_x;
	int			mouse_y;
}				t_keys;

typedef struct s_parsing
{
	char		**map;
	size_t		map_height;
	size_t		map_with;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		cei;
	t_error		error;
}				t_parsing;

typedef struct s_game
{
	t_page		page;
}				t_game;
typedef struct s_cub3d
{
	t_player	player;
	t_mlx		mlx;
	t_parsing	parsing;
	t_game		game;
    t_keys		keys;
}				t_cub3d;

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
void 			img_pix_put(t_cub3d *cub3d, int x, int y, int color);

int				render(t_cub3d *cub3d);

int				ft_close(t_cub3d *cub3d);

int				render_landing_page(t_cub3d *cub3d);
int				render_game_page(t_cub3d *cub3d);
void			fps_counter(t_cub3d *cub3d);
int				render_exit_page(t_cub3d *cub3d);

void			render_background(t_cub3d *cub3d, int color);

int             key_press(int keycode, t_cub3d *cub3d);
int             key_release(int keycode, t_cub3d *cub3d);
int 		    init_keys(t_cub3d *cub3d);
int	mouse_move(int button, int x, int y, t_cub3d *cub3d);

int 		    minimap(t_cub3d *cub3d);

int				update_player_pos(t_cub3d *cub3d);


#endif
