/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:44 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/18 15:13:23 by tviejo           ###   ########.fr       */
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
# include <pthread.h>
# include <sys/time.h>

// dimensions initiales de la fenetre
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1010
// # define WINDOW_WIDTH 1600
// # define WINDOW_HEIGHT 900
//# define WINDOW_WIDTH 1200
//# define WINDOW_HEIGHT 700

// taille initiale (rayon en pixel) du cercle de la minimap
# define MINIMAP_RADIUS 140
// valeur de zoom initiale (taille d'une unité en pixel) pour la minimap
# define MINIMAP_SIZE 12

# define DEG_VERTICAL_FOV 86.3
# define WALK_HEIGHT_RANGE 16.0
# define PLAYER_HEIGHT_FACTOR 0.08

// table des ombrages
# define SHADE_TABLE_SIZE 1024
# define SHADE_PER_DIST 16.0
# define LUM_FADE_DIST 55.0
# define TEX_FADE_DIST 91.0
// facteur d'echelle des textures
# define TEX_SCALE 512.0
// Attention: les textures DOIVENT avoir une taille de TEX_SIZE x TEX_SIZE
// Todo : permettre de charger des texture de n'importe quelle taille et seul
// le carré inclus de coté égal à la plus grande puissance de 2 sera exploité.
# define TEX_SIZE 512

//# define MAX_TEXTURES 30
# define MAX_SPRITES 30

// 1 pour activer le son
# define SOUND_SUPPORT 1
// 1 pour activer la gestion show/hide de la souris
# define MOUSE_SHOWHIDE 1
// 1 pour activer les fonts custom
# define CUSTOM_FONT 1
# define M_SENSITIVITY 0.0015

# define M_HP 10
# define M_HB 0.3
# define M_SPEED 0.1
// unités de distance par sec
# define TRANS_SPEED 2.0
// radians par seconde
# define ROT_SPEED 2.0
// Délai entre chaque tir en seconde
# define SHOOT_DELAY 0.25
// Nombre de munitions
# define NB_AMMO 25

# define B_SND_PLAYER "ffplay -nodisp -autoexit "
//# define SND_MUSIC "assets/sounds/ambiance.mp3"
//# define SND_MUSIC "-volume 35 'assets/sounds/Amon Tobin - Easy Muffin.mp3'"
//# define SND_MUSIC "-volume 65 'assets/sounds/BOSolaris-WearYourSeatBelt.mp3'"
//# define SND_MUSIC "'assets/sounds/DepMode-Agent-Orange.mp3'"
# define SND_MUSIC "assets/sounds/dm-pimpf.aac"
//# define SND_MUSIC "-volume 60 assets/sounds/dm-nothing.aac"
# define SND_SHOOT "assets/sounds/shoot.mp3"
# define SND_STEP "-volume 32 assets/sounds/step.mp3"
# define SND_DAMAGE "assets/sounds/damage.mp3"
# define SND_MONSTER_DEATH "assets/sounds/monster_death.mp3"
# define SND_MONSTER_DAMAGE "assets/sounds/monster_damage.mp3"
# define SND_MONSTER_CLOSE "assets/sounds/monster_close.mp3"
# define SND_MONSTER_CLOSE_2 "assets/sounds/monster_close_2.mp3"
# define SND_MONSTER_FAR "assets/sounds/monster_far.mp3"
# define SND_DOOR_OPEN "assets/sounds/door_open.mp3"
# define SND_DOOR_CLOSE "assets/sounds/door_close.mp3"
# define SND_EMPTY "assets/sounds/empty.mp3"
# define SND_RELOAD "assets/sounds/reload.mp3"
# define SND_YOU_DIED "assets/sounds/you_died.mp3"
# define SND_WELCOME "assets/sounds/welcome.mp3"
# define SND_GOOD_LUCK "assets/sounds/good_luck.mp3"
# define E_SOUND " > /dev/null 2>&1 &"

# define M_HIT_BOX 0.5

# define PATH_SPR_MONSTER1 "assets/sprites/monster_mummie_"
# define NBIMG_SPR_MONSTER1 4

# define IMG_GUN "assets/textures/guns/gun.xpm"
# define IMG_RELOAD "assets/textures/guns/reload.xpm"
# define IMG_FIRE "assets/textures/guns/fire.xpm"

# define IMG_GAME_OVER "assets/textures/game-pages/game_over.xpm"
# define IMG_LANDING "assets/textures/game-pages/landing.xpm"
# define IMG_EXIT "assets/textures/game-pages/exit.xpm"

# define MAP_DEFAULT_FNAME "assets/maps/map_subject.cub"
# define MAP_TAG_TEX_SIZE "TEX_SIZE"
# define MAP_TAG_NORTH_TEX "NO"
# define MAP_TAG_SOUTH_TEX "SO"
# define MAP_TAG_WEST_TEX "WE"
# define MAP_TAG_EAST_TEX "EA"
# define MAP_TAG_OPEN_DOOR_TEX "openDoorTex"
# define MAP_TAG_CLOSED_DOOR_TEX "closedDoorTex"
# define MAP_TAG_CEIL_COLOR "C"
# define MAP_TAG_FLOOR_COLOR "F"
# define MAP_TAG_CEIL_TEX "CeilTex"
# define MAP_TAG_FLOOR_TEX "FloorTex"

//# define NORTH_ANGLE M_PI_2
# define NORTH_ANGLE 1.57079632679489661923
//# define SOUTH_ANGLE (3.0 * M_PI_2)
# define SOUTH_ANGLE 4.71238898038468985769
//# define WEST_ANGLE M_PI
# define WEST_ANGLE 3.14159265358979323846
# define EAST_ANGLE 0.0

# define MAX_MONSTERS 10
# define MAX_MONSTERS_PER_DIFFICULTY 2

//#define _2PI_DIV_1024 6.13592315154256491887e-3

typedef enum e_rendering_mode
{
	RENDER_WIREFRAME,
	RENDER_COLOR,
	RENDER_TEXTURE
}						t_rendering_mode;

typedef enum e_directions
{
	East,
	North,
	West,
	South
}						t_directions;

typedef enum e_keys
{
	k_fire_1 = XK_Control_L,
	k_fire_2 = XK_Control_R,
	k_open_1 = XK_space,
	k_open_2 = XK_e,
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
	k_run = XK_Shift_L,
	k_zoom_in = 65453,
	k_zoom_out = 65451,
	k_sw_rendering_mode = XK_m,
	k_reload = XK_r,
	k_sit = XK_c,
	k_lie_down = XK_x,
	k_enter = 65293,
	k_freeze_monsters = XK_f
}						t_keys;

typedef enum e_page
{
	LANDING_PAGE,
	GAME_PAGE,
	GAME_OVER_PAGE,
	EXIT_PAGE
}						t_page;

typedef enum e_error
{
	NO_ERROR,
	MULTIPLE_PLAYER,
	NO_PLAYER,
	NO_MAP,
	NO_TEXTURE,
	NO_COLOR,
	INVALID_CHAR,
}						t_error;

typedef enum e_door_state
{
	NO_DOOR,
	DOOR_CLOSED,
	DOOR_OPENED,
}						t_door_state;

typedef enum e_tex_id
{
	TXID_FLOOR,
	TXID_CEIL,
	TXID_GUN,
	TXID_FIRE,
	TXID_GUN_RELOAD,
	TXID_GAME_OVER,
	TXID_LANDING,
	TXID_EXIT,
	TXID_MAXIMUM
}						t_tex_id;

typedef enum e_sprite_id
{
	SPR_MONSTER1
}						t_sprite_id;

typedef struct s_monsters
{
	int					id;
	t_pointd			pos;
	int					hp;
	int					random;
	double				dist2_to_player;
	struct s_monsters	*next;
}						t_monsters;

// hot spot: un sprite est affiché en (x,y) il sera centré sur son hotspot
typedef struct s_sprite_img
{
	t_image				img;
	t_point				hspot;
}						t_sprite_img;

/*
typedef struct s_sprite

	// facteur d'echelle
	double				scale;
	// ratio largeur/hauteur
	double				ratio_w_h;
	// position du sprite dans le jeu
	t_pointd			pos;
	// distance au joueur
	double				dist;
	// angle du sprite dans le champ de vision du joueur
	double				angle;
	// hauteur apparente en pixel (calcul rendu)
	int					height;
	// colonne pour le rendu d'une tranche
	int					column;
*/
typedef struct s_sprite
{
	int					nb_images;
	t_sprite_img		*images;
	double				scale;
	double				ratio_w_h;
	t_pointd			pos;
	double				dist;
	double				angle;
	int					height;
	int					column;
	double				x_spot;
}						t_sprite;

typedef struct s_player_inputs
{
	bool				open;
	bool				run;
	bool				mv_forward;
	bool				mv_backward;
	bool				mv_left;
	bool				mv_right;
	bool				turn_left;
	bool				turn_right;
	int					mouse_x;
	int					mouse_y;
	bool				strafe_mode;
	bool				strafe_alt;
	bool				k_fire_1;
	bool				k_fire_2;
	bool				k_open_1;
	bool				k_open_2;
	bool				k_up_1;
	bool				k_up_2;
	bool				k_down_1;
	bool				k_down_2;
	bool				k_left_1;
	bool				k_left_2;
	bool				k_right_1;
	bool				k_right_2;
	bool				k_run;
	bool				ms_fire;
	bool				shoot;
	bool				has_fired;
	bool				reload;
}						t_player_inputs;

/* type t_image is defined in ads_gfx.h
typedef struct s_image
{
	union
	{
		void			*ptr;
		t_img			*_img;
	};
	char				*pixels;
	int					bpp;
	int					line_size;
	int					endian;
	t_point				pos;
	t_size2i			dim;
}						t_image;
*/

// Z-buffer des tranches de murs, exloité pour le rendu des sprites
//	double			*slices_zbuffer;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_image				mlx_img;
	t_image				wall_tex[4];
	t_image				open_door_tex;
	t_image				closed_door_tex;
	t_image				text[TXID_MAXIMUM];
	int					color_floor;
	int					color_ceil;
	double				*slices_zbuffer;
	float				shade_table[SHADE_TABLE_SIZE];
}						t_mlx;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

/*
	// position
	t_pointd		pos;
	// direction: angle in radians
	// East: 0, North: pi/2, West: pi, South: 3pi/2 (-> trigo circle logic)
	double			dir;
	// vertical field of view (radians)
	double			vertical_fov;
	// cumul de la distance parcourue (attention pas la vraie distance !)
	// -> utilisé pour le calcul de walk_height_shift
	double			walk_distance;
	// modification de la hauteur de vue pandant la marche
	double			walk_height_shift;
	// hauteur des yeux
	double			view_height;
*/
typedef struct s_player
{
	t_pointd			pos;
	double				dir;
	double				vertical_fov;
	double				walk_distance;
	double				walk_height_shift;
	double				view_height;
	double				player_pos_z;
	int					health;
	int					ammo;
	double				speed;
	double				shoot_last_time;
}						t_player;

typedef struct s_check_parse
{
	bool				north;
	bool				south;
	bool				west;
	bool				east;
	bool				floor;
	bool				ceil;
}						t_check_parse;

typedef struct s_map
{
	char				**m;
	int					height;
	int					width;
	char				*north_tfname;
	char				*south_tfname;
	char				*west_tfname;
	char				*east_tfname;
	char				*open_door_tfname;
	char				*closed_door_tfname;
	t_color				col_floor;
	t_color				col_ceil;
	double				wall_heightscale;
	t_error				error;
}						t_map;

/*
	// temps du jeu en secondes (mis à jour à chaque nouvelle frame)
	double				time;
	// temps de calcul de la dernière frame en seconde
	double				frame_time;
	// last_tod ne devrait etre exploité que par la fonction update_time()
	// qui met a jour le temps du jeu ('time') ainsi que 'frame_time'.
	// Tous les autres fonctions devraient exploiter time et frame_time et ne
	// pas faire d'appel à gettimeofday()
*/
typedef struct s_game
{
	double				time;
	double				frame_time;
	struct timeval		last_tod;
	t_page				page;
	int					minimap_size;
	int					minimap_radius;
	t_point				minimap_center;
	int					difficulty;
	double				m_speed;
	bool				m_freeze;
	t_rendering_mode	rendering_mode;
}						t_game;

typedef struct s_cub3d
{
	t_player			player;
	int					nb_monsters;
	t_monsters			*monsters;
	int					nb_sprites;
	t_sprite			sprites[MAX_SPRITES];
	t_mlx				mlx;
	t_map				map;
	t_game				game;
	t_player_inputs		inputs;
}						t_cub3d;

/*typedef enum e_looking_dir
{
	look_up,
	look_down,
	look_left,
	look_right,
}	t_looking_dir*/

/*
typedef struct s_raycast

	// image column to render
	int					column;
	// ray angle
	double				angle;
	// coord map du mur trouvé
	t_point				mapc;
	// mur sur intersection verticale ?
	bool				vertical_wall;
	// orientation du mur (Est/North/West/South)
	t_directions		wall_orientation;
	// point d'intersection avec le mur
	t_pointd			wall_inter;

	// point d'intersection avec la prochaine verticale
	t_pointd			v_inter;
	// incréments sur les axes x et y entre 2 intersections verticales
	t_size2d			v_inc;
	// distance à la prochaine intersection verticale
	double				v_dist;
	// distance entre deux intersections verticales
	double				v_dist_inc;

	// point d'intersection avec la prochaine horizontale
	t_pointd			h_inter;
	// incréments sur les axes x et y entre 2 intersections horizontales
	t_size2d			h_inc;
	// distance à la prochaine intersection horizontale
	double				h_dist;
	// distance entre deux intersections horizontales
	double				h_dist_inc;
*/
typedef struct s_raycast
{
	int					column;
	double				angle;
	t_point				mapc;
	bool				vertical_wall;
	t_directions		wall_orientation;
	t_pointd			wall_inter;

	t_pointd			v_inter;
	t_size2d			v_inc;
	double				v_dist;
	double				v_dist_inc;

	t_pointd			h_inter;
	t_size2d			h_inc;
	double				h_dist;
	double				h_dist_inc;
}						t_raycast;

typedef struct s_render_tex
{
	int					height;
	int					y0;
	int					ymax;
	int					y;
	int					tex_x;
	int					tex_y;
	double				ftex_y;
	double				ftex_yinc;
	t_image				*tex;
	t_image				*texceil;
	t_image				*texfloor;
	int					tex_modulo_m1;
	double				shade;
	double				shade_ceilfloor;
	int					pixel;
	double				w_dist;
}						t_render_tex;

typedef struct s_rdr_horiz_tex
{
	double				img_h2;
	double				_1_img_h2;
	double				rel_angle;
	double				tx;
	double				ty;
	double				tx_mul;
	double				ty_mul;
	double				scale_cos;
	double				floor_dist;
	double				pl_tx;
	double				pl_ty;
	double				h_diff;
	double				h_eye;
	double				shade;
	int					x;
	int					y;
	int					ymax;
	t_image				*texture;
	t_image				*img_dst;
}						t_rdr_horiz_tex;

/*typedef struct s_render_horiz_tex
{
	int			line;
	int			x0;
	int			xmax;
	int			x;
	int			tex_x;
	int			tex_y;
	double		ftex_y;
	double		ftex_yinc;
	double		ftex_x;
	double		ftex_xinc;
	t_image		*tex;
	int			tex_modulo_m1;
	double		shade;
	int			pixel;
	double		dist;
	double 		scale;
	double		angle;
}	t_render_horiz_tex;*/

/*
typedef struct s_scaninfo
{
	// coordonnées de map de l'element trouvé
	t_point				mpos;
	// element trouvé
	int					item;
	// distance précise du joueur à l'élément trouvé
*/
typedef struct s_scaninfo
{
	t_point				mpos;
	int					item;
	double				distance;
}						t_scaninfo;

// t_size2i	dim;   //dimensions of rectangle to copy after clipping
typedef struct s_copy_img
{
	t_image				*srcimg;
	t_image				*dstimg;
	t_point				srcpos;
	t_point				dstpos;
	t_size2i			dim;
}						t_copy_img;

typedef struct s_src_dst_x0
{
	int					src;
	int					dst;
}						t_src_dst_x0;

typedef struct s_draw_img
{
	t_image				*srcimg;
	t_image				*dstimg;
	t_point				srcpos;
	t_point				dstpos;
	double				scale;
	int					dst_x0;
	double				src_x0;
	double				src_x;
	double				src_y;
	double				inc;
	t_point				dst;
	t_point				dstmax;
	int					srci_y;
	int					pixel;
}						t_draw_img;
// double		src_xinc;
// double		src_yinc;

void					amlx_enable_win_resizing(t_mlx *mlx, t_size2i min,
							t_size2i max);
void					amlx_update_img_size(t_cub3d *cub);

void					set_game_state(t_cub3d *cub, t_page newstate);
int						parse_cub3d(char *filename, t_cub3d *cub);
bool					begin_with_tag(char *line, char *tag);
bool					get_tag_value(char *line, char *tag, char **value);
bool					is_map(char *line);
int						parse_map(t_cub3d *cub3d, int fd, char *line);
int						find_map_size(int fd, t_cub3d *cub3d);
int						parse_texture(char *line, t_cub3d *cub3d);
bool					parse_color(char *line, t_cub3d *cub3d);
int						find_map(t_cub3d *cub3d, int fd, char *line);
bool					ready_to_parse_map(t_cub3d *cub3d);
void					init_parsing(t_cub3d *cub3d);
void					free_parsing(t_map *map);
void					print_parsing(t_cub3d *cub3d);
char					parse_char(t_cub3d *cub3d, char c, int x, int y);
bool					is_texture(char *line, t_cub3d *cub3d);
bool					is_color(char *line, t_cub3d *cube3d);
int						load_hud_textures(t_cub3d *c);
int						check_parsing(t_cub3d *cub3d);
void					add_back_monster(t_cub3d *cub, t_monsters *new);
void					clear_monsters(t_cub3d *cub);
t_monsters				*new_monster(t_pointd pos, int hp);
void					delete_monster(t_cub3d *cub, int id);

int						mlx_init_data(t_cub3d *cub3d);
int						mlx_start(t_cub3d *cub3d);
int						mlx_close(t_mlx *mlx);
int						mlx_create_img(t_cub3d *cub3d, int width, int height);
int						mlx_set_hooks_n_loop(t_cub3d *cub3d);
int						ft_free_img(t_mlx *mlx);
int						ft_init_img(t_mlx *mlx);
int						ft_close(t_cub3d *cub3d, char *errmsg);
int						on_win_close(t_cub3d *cub3d);
int						on_win_change(t_cub3d *cub3d);

int						load_texture(void *mlx_ptr, char *filename,
							t_image *img);

void					render_frame(t_cub3d *cub);
void					render_ray_colored(t_cub3d *c, t_raycast *rc,
							int wallitem);
void					render_ray_textured(t_cub3d *c, t_raycast *rc,
							int wallitem);
int						render_ray_tex_init(t_cub3d *c, t_raycast *rc,
							t_render_tex *rt, int item);
void					init_ray_v_inter(t_raycast *rc, double angle,
							t_pointd pos);
void					init_ray_h_inter(t_raycast *rc, double angle,
							t_pointd pos);
int						scan_in_front(t_cub3d *c, t_scaninfo *si, double angle);

int						render(t_cub3d *cub3d);
int						render_landing_page(t_cub3d *cub3d);
int						render_game_page(t_cub3d *cub3d);
void					update_time(t_game *game);
void					draw_fps(t_cub3d *cub3d);
int						render_exit_page(t_cub3d *cub3d);

int						on_key_press(int keycode, t_cub3d *cub3d);
int						on_key_release(int keycode, t_cub3d *cub3d);
void					minimap_keys(t_cub3d *cub3d, int keycode);
void					difficulty_keys(t_cub3d *cub3d, int keycode);
int						init_keys(t_cub3d *cub3d);
void					mouse_move(t_cub3d *cub3d);
void					key_release_player_2(int keycode, t_cub3d *cub3d);

int						draw_minimap(t_cub3d *cub3d);
void					print_wall(t_cub3d *cub, t_point pos);
void					print_player(t_cub3d *cub);
void					print_monsters(t_cub3d *cub);
void					print_map_border(t_cub3d *cub, int r, int color);

int						update_player_pos(t_cub3d *cub3d);
void					rotate_player(t_player *p, double angle);
double					angles_add(double alpha, double beta);

t_pointd				collides_wall(t_cub3d *cub, t_pointd old_pos);
int						interact_door(t_cub3d *cub, t_pointd pos);
void					move_monsters(t_cub3d *cub);
void					shoot_monsters(t_cub3d *cub);
bool					is_m_wall(t_cub3d *cub, double x, double y);
bool					is_wall(t_cub3d *cub, int x, int y);

t_directions			get_wall_orientation(double ray_angle,
							bool vertical_wall);
int						get_wall_color(t_directions orientation,
							double distance, int wallitem);
t_image					*get_wall_texture(t_cub3d *cub,
							t_directions orientation, double distance,
							int item);
void					draw_floor_n_ceil(t_cub3d *c);

void					draw_hud(t_cub3d *cub);
void					draw_health_bar(t_cub3d *cub);
void					shade_image(t_image *img, int health);

void					update_health(t_cub3d *cub);

int						render_game_over_page(t_cub3d *cub3d);

bool					monster_is_present(t_cub3d *cub, t_pointd pos);

int						on_mouse_btn_press(int btn, int x, int y, t_cub3d *cub);
int						on_mouse_btn_release(int btn, int x, int y,
							t_cub3d *cub);

void					play_sound(char *sound, t_cub3d *cub);
void					kill_sound(void);
void					sound_close_monster(t_cub3d *cub);

void					gunfire(t_cub3d *cub);
void					tryfire(t_cub3d *cub);
void					reload(t_cub3d *cub);
void					change_height_player(t_cub3d *cub, double height);

void					copy_image(t_image *srcimg, t_point srcpos,
							t_image *dstimg, t_point dstpos);
void					draw_image(t_draw_img di);
void					draw_image_autoscale(t_image *src, t_image *dst);

int						load_sprites(t_cub3d *c);
void					free_sprites(t_cub3d *c);

void					qsort_monsters(t_monsters **tab, int nb_elem);
void					draw_monsters(t_cub3d *cub);
void					draw_sprite(t_cub3d *c, t_sprite *spr, int img_num);
void					draw_slice(t_cub3d *c, t_sprite *spr, int img_num);

// void				draw_floor_n_ceil_textured(t_cub3d *c);
void					render_tex_ceil_n_floor(t_cub3d *c, t_raycast *rc,
							t_render_tex *r);
void					render_floor_column(t_rdr_horiz_tex t);
void					render_ceil_column(t_rdr_horiz_tex t);

long					ft_labs(long n);
bool					is_invalid_line(char *line);

#endif