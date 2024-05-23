CC = cc
CFLAGS = -Wextra -Wall -Werror -g
LDFLAGS = -LMLX42/build -lmlx42 -ldl -lglfw -pthread -lm
INCLUDES = -Iinc -Iinc/game -Iinc/engine -IMLX42/include/MLX42
HEADERS = inc/game/engine/view.h inc/game/game.h inc/defs.h inc/error.h inc/game_data.h inc/keys.h inc/map.h inc/map_data.h inc/moves.h inc/tile.h inc/vec.h
SRC = 	src/main.c \
		src/game/render/test.c \
		src/map/map.c \
		src/map/tile.c \
		src/parsing/main.c \
		src/parsing/parsing.c \
		src/parsing/parsing_utils.c \
		src/parsing/extraction.c \
		src/parsing/error_manager.c \
		src/parsing/libft.c \
		src/parsing/argument_check.c \
		src/parsing/get_next_arg.c \
		src/parsing/char_check.c \
		src/parsing/light_utils.c \
		src/parsing/flooding.c \
		src/parsing/map_creation.c \
		src/parsing/deinit.c \
		src/parsing/map_manager.c \
		src/parsing/map_scrap_utils.c \
		src/game/render/window_clear.c \
		src/game/game_loop.c \
		src/game/refresh/move_player.c \
		src/game/error_management.c \
		src/minimap/moves.c \
		src/minimap/next_move.c \
		src/minimap/directions.c \
		src/minimap/minimap_utils.c \
		src/minimap/init.c \
		src/minimap/pixel_treat.c \
		src/minimap/player_move.c \
		src/game/cleaning.c \
		src/game/init_game.c \
		src/game/init_data.c \
		src/game/render/render.c \
		src/game/render/casting.c \
		src/game/render/utils_cast.c \
		src/game/render/utils_render.c \
		src/game/render/rending_part.c \
		src/minimap/init_utils.c
OBJ = $(SRC:.c=.o)
MLX42 = MLX42/build/libmlx42.a
LIBS = MLX42/
NAME = cub3D

COLOR_GREEN = \x1b[1;32m
COLOR_YELLOW = \x1b[1;33m
COLOR_RED = \x1b[1;31m
COLOR_BLUE = \x1b[1;34m
COLOR_PURPLE = \x1b[1;35m
COLOR_GRAY = \x1b[0;90m
COLOR_RESET = \e[0m

ifdef DEBUG
	CFLAGS = -Wextra -Wall -g
endif
ifdef CHECK
	CFLAGS += -fsanitize=address
endif
ifndef NO_SILENT
.SILENT:
endif

all: $(NAME)

$(NAME): $(MLX42) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LDFLAGS)
	@printf "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $(NAME)\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@printf "$(COLOR_PURPLE)Compiled:$(COLOR_RESET) $< $(COLOR_GRAY)$(CC) $(CFLAGS)$(COLOR_RESET)\n"

$(MLX42) :
	@printf "$(COLOR_YELLOW)Compiling $@$(COLOR_RESET)\n"
	@cd MLX42 && cmake -B build .
	@make -C MLX42/build
	@printf "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $@\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf MLX42/build

re: fclean all
