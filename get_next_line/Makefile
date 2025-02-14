NAME = libgnl.a

SRC = get_next_line.c\
	  get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INCDIR = ../inc/

INC = get_next_line.h

CC = cc 

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) -I$(INCDIR) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
