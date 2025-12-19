SRCS = srcs/main.c \
		srcs/ft_window.c \
		srcs/hooks.c \
		srcs/player.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = MacroLibX/libmlx.so -lSDL2
NAME = solong
INCLUDE_DIRS = -I MacroLibX/includes -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

.PHONY: all re clean fclean
