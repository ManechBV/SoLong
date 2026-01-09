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
		srcs/ft_greater.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g 
MLX_FLAGS = MacroLibX/libmlx.so -lSDL2
NAME = solong
INCLUDE_DIRS = -I MacroLibX/includes -I includes

all: $(NAME)

$(NAME): ft_printf $(OBJS) 
	$(CC) $(OBJS) srcs/ft_printf/libftprintf.a $(MLX_FLAGS) $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

ft_printf:
	make -C srcs/ft_printf

re: fclean all

clean:
	make clean -C srcs/ft_printf
	rm -rf $(OBJS)

fclean:
	make fclean -C srcs/ft_printf
	rm -rf $(NAME)

.PHONY: all re clean fclean ft_printf
