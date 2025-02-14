NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g

MFLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lbsd

CC = cc

MLX_LIBDIR = ./mlx/

MLX_LIB = $(MLX_LIBDIR)libmlx.a

FT_PRINTF_LIBDIR = ./ft_printf/

FT_PRINTF_LIB = $(FT_PRINTF_LIBDIR)libftprintf.a

GNL_LIBDIR = ./get_next_line/

GNL_LIB = $(GNL_LIBDIR)libgnl.a

SRCDIR = ./src/

INCDIR = ./inc/

FILES = main\
load_map\
render_map\
exit_game\
utils\
error_handle\
error_handle_2\
game_mechanics\
check_map\
check_map_2\

SRC =  $(addprefix $(SRCDIR), $(addsuffix .c, $(FILES)))

OBJ = $(SRC:.c=.o) 

INC = $(INCDIR)so_long.h

all: aux_libraries $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(MFLAGS) $(MLX_LIB) $(FT_PRINTF_LIB) $(GNL_LIB) -o $@

%.o: %.c
	$(CC) -I$(INCDIR) $(CFLAGS) -c $< -o $@

aux_libraries:
	@make -C $(MLX_LIBDIR) all
	@make -C $(FT_PRINTF_LIBDIR) all
	@make -C $(GNL_LIBDIR) all

clean:
	rm -f $(OBJ)
	@make -C $(MLX_LIBDIR) clean
	@make -C $(FT_PRINTF_LIBDIR) clean
	@make -C $(GNL_LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_LIBDIR) fclean
	@make -C $(FT_PRINTF_LIBDIR) fclean
	@make -C $(GNL_LIBDIR) fclean

re: fclean all

.PHONY: clean fclean all re aux_libraries
