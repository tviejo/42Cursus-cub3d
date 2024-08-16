NAME		=	cube3d

SRC_DIR		=	srcs/

OBJ_DIR     =   objs/

SRCS		+= parsing/parsing.c

SRCS		+= main.c

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC			=	cc

CFLAGS		=	-g3 -Wall -Wextra -Werror

LIBFT 		= 	libft/libft.a

MLX			=	mlx/libmlx.a

INCLUDES 	= 	-I includes/ -I libft/includes/
INCLUDES	+= 	-I/opt/X11/include -Imlx

LIBS		=   -L libft -lft

MLX_FLAGS	=	-lm -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

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

$(LIBFT):
				@$(PRINT_LOADING)
				$(MAKE) -s -C libft/

$(MLX):			
				@$(PRINT_LOADING_MLX)
				$(MAKE) >/dev/null -C  mlx/

${NAME}: 		${OBJS}
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)%.o: %.c
				@echo "$(BLUE)Compiling: $@ $(END)"
				mkdir -p $(OBJ_DIR) $(OBJ_DIR)parsing/
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				$(RM) -r $(OBJ_DIR)
				${RM} ${OBJS}
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

.PHONY: all clean fclean re bonus libft
.SILENT: