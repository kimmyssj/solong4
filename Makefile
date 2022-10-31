NAME = solong

SRC_A = main.c gnl.c libft.c str_parse.c \
		valid_check.c indexof.c initialize.c map_img_maker.c \
		itoa.c key_hook.c \

OBJ_A = $(SRC_A:.c=.o)

LIBMLX = mlx/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_A) $(LIBMLX)
	$(CC) $(CFLAG) $(LIBMLX) -framework OpenGL -framework Appkit $^ -o $@

$(LIBMLX) :
		cd mlx; make

%.o : %.c
	$(CC) $(CFLAG) -c $<

clean :
	rm -f $(OBJ_A)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
