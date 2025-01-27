NAME = program

SRCS = main.c
OBJS = $(SRCS:.c=.o)

MLX42_DIR = ./MLX42
MLX42_INC = $(MLX42_DIR)/include
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror -I$(MLX42_INC)
LDFLAGS = $(MLX42_LIB) -ldl -lglfw -lm -pthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
