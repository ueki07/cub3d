CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBSUPP = -lm minilibx/libmlx.a

INCLUDE = -Iminilibx -Ilibft -Iincludes

#INCLUDE = minilibx/mlx.h libft/libft.h

SRC = sources/main.c sources/parsing/param.c \
	sources/parsing/bytes.c sources/parsing/check_map.c \
	sources/parsing/handle_map.c sources/utils.c \
	sources/render/handle_mlx.c sources/render/init_raycasting.c \
	sources/render/print_walls.c sources/render/moves.c \
	sources/render/menhir.c

SRCDIR = parsing render

OBJDIR = build

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
#error in objs rule because if equal to src and not (ex) .o file with same name

LIBFT = libft/libft.a

NAME = cub3d

MINILIBX = minilibx/libmlx.a

all: $(MINILIBX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBSUPP) -lXext -lX11 -lm

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C libft

$(MINILIBX):
	@$(MAKE) -s -C minilibx

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -s -C libft clean
	@$(MAKE) -s -C minilibx clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re
