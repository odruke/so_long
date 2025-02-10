NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g

MFLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lbsd

CC = cc

MLX_LIBDIR = ./mlx/

MLX_LIB = $(MLX_LIBDIR)libmlx.a

LIBFT_LIBDIR = ./libft/

LIBFT_LIB = $(LIBFT_LIBDIR)libft.a

GNL_LIBDIR = ./get_next_line/

GNL_LIB = $(GNL_LIBDIR)libgnl.a

SRC =  test.c\
	   ./utils/load_map.c\
	   ./utils/render_map.c\
	   ./utils/exit_game.c\
	   ./utils/utils.c\
	   ./utils/error_handle.c\
	   ./utils/game_mechanics.c\
	   ./utils/check_map.c\
	   


OBJ = $(SRC:.c=.o) 

INC = so_long.h

all: aux_libraries $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(MFLAGS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

aux_libraries:
	@make -C $(MLX_LIBDIR) all
	@make -C $(LIBFT_LIBDIR) all
	@make -C $(GNL_LIBDIR) all

clean:
	rm -f $(OBJ)
	@make -C $(MLX_LIBDIR) clean
	@make -C $(LIBFT_LIBDIR) clean
	@make -C $(GNL_LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_LIBDIR) fclean
	@make -C $(LIBFT_LIBDIR) fclean
	@make -C $(GNL_LIBDIR) fclean

re: fclean all

.PHONY: clean fclean all re aux_libraries
