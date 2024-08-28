/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ads_gfx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:58:41 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/08/28 23:19:06 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADS_GFX_H
# define ADS_GFX_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <math.h>
# include "float.h"
# include <sys/time.h>

// #define DEG2RAD (M_PI/180.0)
# define DEG2RAD 1.74532925199433e-2

# define COL_BLACK    0xFF000000
# define COL_WHITE    0xFFffffff
# define COL_GREY     0xFF777777
# define COL_LT_GREY  0xFFbfbfbf
# define COL_DK_GREY  0xFF3f3f3f
# define COL_RED      0xFFff0000
# define COL_DK_RED   0xff7f0000
# define COL_LT_RED   0xFFff7f7f
# define COL_GREEN    0xFF00ff00
# define COL_DK_GREEN 0xFF007f00
# define COL_LT_GREEN 0xff7fff7f
# define COL_BLUE     0xFF0000ff
# define COL_NAVY     0xff00007f
# define COL_LT_BLUE  0xFF7f7fff
# define COL_YELLOW   0xFFffff00
# define COL_BROWN    0xFF8f8f3f
# define COL_DK_BROWN 0xFF7f7f00
# define COL_MAGENTA  0xFFff00ff
# define COL_ORANGE   0xFFff7f00

# define NUMBER_OF_COMMAND 14
# define NUM_OF_KEY_MOD 6
// Power of two
# define PAL_NUM_COLORS 1024
# define PALNB			1023
# define INFOBAR_HEIGHT 20

/*
enum e_keymod
{
	leftShift,
	rightShift,
	leftCtrl,
	rightCtrl,
	leftAlt,
	rightAlt
};

enum e_command
{
	zoomIn,
	zoomOut,
	mvUp,
	mvDown,
	mvLeft,
	mvRight,
	rotUp,
	rotDown,
	rotLeft,
	rotRight,
	rotZinc,
	rotZdec,
	scaleZinc,
	scaleZdec,
	number_of_command
};
*/
typedef unsigned int	t_uint;
typedef long			t_time_ms;
typedef t_time_ms		t_duree_ms;

typedef struct s_point
{
	union
	{
		int	x;
		int	width;
		int	min;
	};
	union
	{
		int	y;
		int	height;
		int	max;
	};
}	t_point;

typedef struct s_point	t_size2i;
typedef struct s_point	t_range;

typedef struct s_pointd
{
	union
	{
		double	x;
		double	width;
		double	min;
	};
	union
	{
		double	y;
		double	height;
		double	max;
	};
}	t_pointd;

typedef struct s_pointd	t_size2d;
typedef struct s_pointd	t_ranged;

typedef struct s_rect
{
	union
	{
		struct
		{
			int	x0;
			int	y0;
			int	x1;
			int	y1;
		};
		struct
		{
			int	xmin;
			int	ymin;
			int	xmax;
			int	ymax;
		};
		struct
		{
			t_point	p0;
			t_point	p1;
		};
	};
}	t_rect;

typedef struct s_rect	t_range2;

typedef struct s_rectd
{
	union
	{
		struct
		{
			double	x0;
			double	y0;
			double	x1;
			double	y1;
		};
		struct
		{
			double	xmin;
			double	ymin;
			double	xmax;
			double	ymax;
		};
		struct
		{
			t_pointd	p0;
			t_pointd	p1;
		};
	};
}	t_rectd;

typedef struct s_rectd	t_range2d;

typedef struct s_range3
{
	int	xmin;
	int	ymin;
	int	zmin;
	int	xmax;
	int	ymax;
	int	zmax;
}	t_range3i;

typedef struct s_range3d
{
	double	xmin;
	double	ymin;
	double	zmin;
	double	xmax;
	double	ymax;
	double	zmax;
}	t_range3d;

typedef struct s_pt3d
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_pt3d;

typedef struct s_pt2d
{
	int		x;
	int		y;
	double	z;
	double	z0;
	int		color;
}	t_pt2d;

typedef struct s_draw_line_vars
{
	int			error;
	t_size2i	inc;
	t_point		pt;
}	t_draw_line_vars;

typedef struct s_hue_range
{
	double	start;
	double	end;
	double	direction;
}	t_hue_range;

typedef struct s_matrix
{
	double	m11;
	double	m12;
	double	m13;
	double	m14;
	double	m21;
	double	m22;
	double	m23;
	double	m24;
	double	m31;
	double	m32;
	double	m33;
	double	m34;
	double	m41;
	double	m42;
	double	m43;
	double	m44;
}	t_matrix;

typedef struct s_matrix_inv
{
	double	c0;
	double	c1;
	double	c2;
	double	c3;
	double	c4;
	double	c5;
	double	s0;
	double	s1;
	double	s2;
	double	s3;
	double	s4;
	double	s5;
}	t_matrix_inv;

typedef struct s_fdfmap
{
	t_size2i	dim;
	t_range3d	range;
	t_pt3d		**points;
	t_pt2d		**pts2d;
	char		*name;
	int			max_height;
	t_matrix	transform;
	t_matrix	camera;
	t_matrix	projection;
	double		viewport_xmul;
	double		viewport_ymul;
	double		viewport_xadd;
	double		viewport_yadd;
	bool		has_perspective;
	bool		raw_clipping;
	bool		z_clipping;
	bool		use_z_color_palette;
	bool		palette_rotate;
	int			palette[PAL_NUM_COLORS];
	double		palrotbase;
	double		palrotspeed;
	double		pal_zrange;
	double		palidx0;
	double		palidx_inc;
	double		palnbc_div_zrange;
}	t_fdfmap;

/*typedef struct s_map_load
{
	t_fdfmap 		*map;
	int 		max_height;
	int			fd;
} 	s_map_load;*/

typedef struct s_image
{
	union
	{
		void	*handle;
		t_img	*_img;
	};
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
	t_point		pos;
	t_size2i	dim;
}	t_image;

typedef struct s_app
{
	union
	{
		void	*mlx;
		t_xvar	*_mlx;
	};
	union
	{
		void		*win;
		t_win_list	*_win;
	};
	t_image		img;
	t_image		img_infobar;
	t_fdfmap	*map;
	int			keycmd[NUMBER_OF_COMMAND];
	bool		keymod[NUM_OF_KEY_MOD];
	bool		need_help;
	int			fps;
	int			frame;
	t_time_ms	time0;
	t_duree_ms	duree;
}	t_app;

void		amlx_set_win_minmax(t_xvar *xvar, Window win,
				t_size2i min, t_size2i max);
void		amlx_enable_win_resizing(t_app *app);
int			amlx_create_img_buffer(t_app *app, int width, int height);
void		amlx_get_win_size(void *mlx, void *win, int *width, int *height);
void		amlx_update_app_img_size(t_app *app);
int			amlx_free_and_exit(t_app *app);

t_time_ms	get_time(void);
t_duree_ms	get_duree(t_time_ms time0);
t_duree_ms	get_duree_update_t0(t_time_ms *time0);

void		img_put_pixel(t_image *img, int x, int y, int color);
void		img_put_pixel32(t_image *img, int x, int y, int color);
void		img_put_pixel32_safe(t_image *img, t_uint x, t_uint y, int color);

//void		draw_h_line(t_image *img, t_pt2d p0, t_pt2d p1);
//void		draw_h_line_safe(t_image *img, t_pt2d p0, t_pt2d p1);
//void		draw_v_line(t_image *img, t_pt2d p0, t_pt2d p1);
//void		draw_v_line_safe(t_image *img, t_pt2d p0, t_pt2d p1);
//void		draw_line_fast(t_mlx *mlx, t_pt2d *p0, t_pt2d *p1);  => cub3d.h
void		draw_line_safe(t_image *img, t_pt2d p0, t_pt2d p1);
void		draw_line_color(t_image *img, t_pt2d *p0, t_pt2d *p1);
void		draw_line_palette(t_fdfmap *map, t_image *img, t_pt2d *p0,
				t_pt2d *p1);
//void		draw_line(t_mlx *mlx, t_pt2d p0, t_pt2d p1);  => cub3d.h

int			get_inter_color(int c1, int c2, double ramp);

void		img_clear(t_image *img);
void		img_clear128(t_image *img);
void		img_fill(t_image *img, int color);
void		img_fill128(t_image *img, int color);

void		mat_set_identity(t_matrix *mat);
t_matrix	mat_mul(t_matrix a, t_matrix b);
t_matrix	mat_get_inverse(t_matrix *mat);
void		mat_translate(t_matrix *mat, double x, double y, double z);
void		mat_set_translate(t_matrix *mat, double x, double y, double z);
void		mat_set_scale(t_matrix *mat, double x, double y, double z);
void		mat_set_rotate_x(t_matrix *mat, double angle);
void		mat_set_rotate_y(t_matrix *mat, double angle);
void		mat_set_rotate_z(t_matrix *mat, double angle);
void		mat_set_rotate(t_matrix *mat, double x, double y, double z);
t_matrix	mat_ortho_project(double fov, double aspect,
				double near, double far);
t_matrix	mat_persp_project(double fov, double aspect,
				double near, double far);
void		set_viewport(t_fdfmap *map, t_size2i dim, t_point offset);

#endif
