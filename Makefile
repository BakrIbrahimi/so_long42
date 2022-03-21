NAME = so_long
B_NAME = so_long_bonus
BONUS_NAME = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
M_SRCS = so_long.c \
	src/moving_utils.c \
	src/moving.c \
	src/add_line.c \
	src/check_line.c \
	src/check_name.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/parser.c \
	src/put_img.c \
	src/render.c \
	so_long_utils.c

B_SRCS = bonus/so_long_bonus.c \
	bonus/src/moving_utils_bonus.c \
	bonus/src/moving_bonus.c \
	bonus/src/add_line_bonus.c \
	bonus/src/check_line_bonus.c \
	bonus/src/check_name_bonus.c \
	bonus/src/get_next_line_bonus.c \
	bonus/src/get_next_line_utils_bonus.c \
	bonus/src/parser_bonus.c \
	bonus/src/put_img_bonus.c \
	bonus/src/render_bonus.c \
	bonus/src/put_img2_bonus.c \
	bonus/src/animation_bonus.c \
	bonus/src/exit_utils_bonus.c \
	bonus/src/ft_itao_bonus.c \
	bonus/so_long_utils_bonus.c

M_OBJ = $(M_SRCS:.c=.o)

B_OBJ = $(B_SRCS:.c=.o)

all : $(NAME)

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(FLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx
%.o : %.c so_long_bonus.h
$(NAME): $(M_OBJ)
	$(CC) $(FLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx
%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(M_OBJ)	$(B_OBJ)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all bonus
