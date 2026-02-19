SRCS = srcs/main.c \
		srcs/ft_window.c \
		srcs/hooks.c \
		srcs/player.c \
		srcs/map.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/map_check.c \
		srcs/map_check_flood.c \
		srcs/map_draw.c \
		srcs/ft_strichr.c \
		srcs/player_move.c \
		srcs/ft_count_collec.c \
		srcs/map_check_collec.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = MacroLibX/libmlx.so -lSDL2
NAME = solong
INCLUDE_DIRS = -I MacroLibX/includes -I includes

all: make_objs_dir $(NAME)

make_objs_dir:
	mkdir -p objs

$(NAME): mlx ft_printf $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) srcs/ft_printf/libftprintf.a $(MLX_FLAGS) $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

ft_printf:
	make -C srcs/ft_printf

mlx:
	make -j -C MacroLibX

re: fclean all

clean:
	rm -rf $(OBJS)
	make clean -C srcs/ft_printf
	make clean -C MacroLibX

fclean:
	rm -rf $(NAME)
	make fclean -C srcs/ft_printf
	make fclean -C MacroLibX

.PHONY: all re clean fclean ft_printf mlx make_objs_dir
