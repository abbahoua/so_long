NAME = so_long
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC = 	main_map.c\
		ft_error.c\
		ft_split.c\
		ft_strlcpy.c\
		get_next_line.c\
		get_next_line_utils.c\
		file.c\
		mlx.c\
		hook.c\
		ft_putnbr.c\
		main.c\

OBJ = $(SRC:.c=.o)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME) 

re: fclean all

.PHONY : all clean fclean re