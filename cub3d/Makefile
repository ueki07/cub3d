CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBSUPP = -lm minilibx/libmlx.a

INCLUDE = -Iminilibx -Ilibft -Iincludes

SRC = sources/main.c sources/parsing/param.c \
	sources/parsing/bytes.c sources/parsing/check_map.c \
	sources/parsing/handle_map.c sources/utils.c \
	sources/render/handle_mlx.c sources/render/init_raycasting.c \
	sources/render/print_walls.c sources/render/moves.c \
	sources/render/menhir.c

SRCDIR = parsing render

MLX_GIT = https://github.com/42paris/minilibx-linux.git
MLXDIR = minilibx-linux
MLX = $(MLXDIR)/libmlx.a

OBJDIR = build

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

LIBFT = libft/libft.a

NAME = cub3d

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "$(YELLOW)Cloning MiniLibX...$(DEFAULT)" ; \
		git clone $(MLX_GIT) $(MLXDIR) ; \
	else \
		echo "$(GREEN)MiniLibX directory already exists.$(DEFAULT)" ; \
	fi
	@echo "$(YELLOW)Compiling MiniLibX...$(DEFAULT)"
	@$(MAKE) -C $(MLXDIR)
	@echo "$(GREEN)MiniLibX compiled!$(DEFAULT)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBSUPP) -lXext -lX11 -lm

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C libft

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -s -C libft clean
	@if [ -d "$(MLXDIR)" ]; then $(MAKE) -C $(MLXDIR) clean; fi
	@echo "$(YELLOW)object files deleted.$(DEFAULT)"

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MLXDIR)
	@echo "$(RED)all files deleted.$(DEFAULT)"
	@$(MAKE) -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re

