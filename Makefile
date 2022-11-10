NAME = so_long

SRC_A = main.c gnl.c libft.c str_parse.c \
		valid_check.c indexof.c initialize.c map_img_maker.c \
		itoa.c key_hook.c is_path_valid.c plague.c \

OBJ_A = $(SRC_A:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_A)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework Appkit $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ_A)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
