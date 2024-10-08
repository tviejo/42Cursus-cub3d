NAME		=	cub3D

NAME_BONUS	=	cub3D_bonus

SRC_DIR		=	srcs/

OBJ_DIR     =   objs/

SRCS		+= draw/draw_line_main.c
SRCS		+= draw/draw_line_fast.c
SRCS		+= draw/image_fill.c
SRCS		+= draw/put_pixel.c
SRCS		+= draw/rectangle.c

SRCS		+= sprite/draw_sprite.c
SRCS		+= sprite/draw_slice.c
SRCS		+= sprite/load.c
SRCS		+= sprite/load_texture.c
SRCS		+= sprite/copy_image.c
SRCS		+= sprite/draw_image.c
SRCS		+= sprite/quicksort.c
SRCS		+= sprite/init_sprite.c

SRCS		+= ray_caster/render_frame.c
SRCS		+= ray_caster/render_colored.c
SRCS		+= ray_caster/render_textured.c
SRCS		+= ray_caster/rdr_tex_loop.c
SRCS		+= ray_caster/floor_n_ceil.c
SRCS		+= ray_caster/rdr_tex_floor_n_ceil.c
SRCS		+= ray_caster/render_utils.c

SRCS		+= parsing/parsing.c
SRCS		+= parsing/parsing_utils.c
SRCS		+= parsing/parsing_utils_2.c
SRCS		+= parsing/init_parsing.c
SRCS		+= parsing/parse_map.c
SRCS		+= parsing/parse_colors.c
SRCS		+= parsing/parse_textures.c
SRCS		+= parsing/free_parsing.c
SRCS		+= parsing/print_parsing.c
SRCS		+= parsing/check_parsing.c
SRCS		+= parsing/monster_utils.c

SRCS		+= mlx_utils/amlx.c
SRCS		+= mlx_utils/mlx_utils.c
SRCS		+= mlx_utils/mlx_create_image.c
SRCS		+= mlx_utils/mlx_looping.c
SRCS		+= mlx_utils/init_data.c

SRCS		+= render/render.c

SRCS		+= close/close.c

SRCS		+= game_page/fps_counter.c
SRCS		+= game_page/time.c

SRCS		+= landing_page/landing_page.c

SRCS		+= exit_page/exit_page.c

SRCS		+= keys/keys.c
SRCS		+= keys/keys_utils.c
SRCS		+= keys/mouse.c
SRCS		+= keys/keys_2.c

SRCS		+= player/move.c
SRCS		+= player/move_utils.c
SRCS		+= player/collision.c
SRCS		+= player/health.c
SRCS		+= player/gun.c

SRCS		+= hud/load_images.c

SRCS		+= game_over_page/game_over.c

SRCS		+= main.c

SRCS_BONUS	=	game_page/game_page_bonus.c

SRCS_BONUS		+= interaction/door_bonus.c
SRCS_BONUS		+= interaction/monster_bonus.c
SRCS_BONUS		+= interaction/monster2_bonus.c
SRCS_BONUS		+= interaction/monster_utils_bonus.c

SRCS_BONUS		+= hud/hud_bonus.c
SRCS_BONUS		+= hud/damage_bonus.c
SRCS_BONUS		+= hud/health_bar_bonus.c

SRCS_BONUS		+= minimap/minimap_bonus.c
SRCS_BONUS		+= minimap/print_player_bonus.c
SRCS_BONUS		+= minimap/print_walls_bonus.c
SRCS_BONUS		+= minimap/print_map_border_bonus.c
SRCS_BONUS		+= minimap/print_monster_bonus.c

SRCS_BONUS		+= ray_caster/scanner_bonus.c

SRCS_BONUS		+= sound/sound_bonus.c

SRCS_BONUS		+= parsing/parse_map_utils_bonus.c

ifneq ($(MAKECMDGOALS), bonus)
	SRCS += game_page/game_page.c
	SRCS += sound/sound.c
	SRCS += parsing/parse_map_utils.c
endif

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_BONUS	=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -g3

LIBFT 		= 	libft/libft.a

MLX			=	mlx/libmlx.a

INCLUDES 	= 	-I includes/ -I libft/includes/
INCLUDES	+= 	-I/opt/X11/include -Imlx

LIBS		=   -L libft -lft

MLX_FLAGS	=	-lm -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

D_FILES		=	$(OBJS:.o=.d)

RM			=	rm -f

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m
BOLD_START=\e[1m
BOLD_END=\e[0m

ifeq ($(debug), true)
	CFLAGS += -g3 -fsanitize=address,undefined
endif

ifeq ($(optimax), true)
	CFLAGS += -O3 -Ofast -ffast-math
else
	CFLAGS += -O2
endif

define PRINT_LOADING
	@printf "$(GREEN)Compiling libft["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n$(END)"
endef

define PRINT_LOADING_MLX
	@printf "$(GREEN)Compiling mlx  ["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n$(END)"
endef

all: 			$(LIBFT) $(MLX) ${NAME}
				@echo "$(GREEN)$(BOLD_START)${NAME} created$(BOLD_END)$(END)"

bonus:			$(LIBFT) $(MLX) ${NAME_BONUS}
				@echo "$(GREEN)$(BOLD_START)${NAME_BONUS} created$(BOLD_END)$(END)"

$(LIBFT):
				@$(PRINT_LOADING)
				$(MAKE) -s -C libft/

$(MLX):			
				@$(PRINT_LOADING_MLX)
				$(MAKE) >/dev/null -C  mlx/

${NAME}: 		${OBJS}
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(MLX_FLAGS)


${NAME_BONUS}: 	${OBJS} ${OBJS_BONUS}
				$(CC) $(CFLAGS) ${OBJS} $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS) $(MLX_FLAGS)

$(OBJ_DIR)%.o: %.c
				@echo "$(BLUE)Compiling: $@ $(END)"
				mkdir -p $(OBJ_DIR) $(OBJ_DIR)draw/ $(OBJ_DIR)sprite/ $(OBJ_DIR)ray_caster/ $(OBJ_DIR)parsing/ $(OBJ_DIR)mlx_utils/ $(OBJ_DIR)close/ $(OBJ_DIR)render/ $(OBJ_DIR)game_page/ $(OBJ_DIR)landing_page/ $(OBJ_DIR)exit_page/ $(OBJ_DIR)keys/ $(OBJ_DIR)minimap/ $(OBJ_DIR)player/ $(OBJ_DIR)interaction/ $(OBJ_DIR)hud/ $(OBJ_DIR)game_over_page/ $(OBJ_DIR)sound/
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				$(RM) -r $(OBJ_DIR)
				${RM} ${OBJS} ${OBJS_BONUS}
				${RM} ${D_FILES}
				@echo "$(RED)Clean libft$(END)"
				$(MAKE) clean -s -C ./libft/
				@echo "$(RED)Clean mlx$(END)"
				$(MAKE) clean >/dev/null -C ./mlx/
				@echo "$(GREEN)$(BOLD_START)Clean done$(BOLD_END)$(END)"

fclean: clean
				${RM} ${NAME} ${NAME_BONUS}
				@echo "$(RED)Fclean libft$(END)"
				$(MAKE) fclean -s -C ./libft/
				@echo "$(RED)Fclean mlx$(END)"
				$(MAKE) clean >/dev/null -C ./mlx/
				@echo "$(GREEN)$(BOLD_START)Fclean done$(BOLD_END)$(END)"

re: fclean all

sinclude $(D_FILES)

.PHONY: all clean fclean re bonus libft
.SILENT: