NAME = push_swap

SRCS = main.c push_swap_init.c rotate_cmd.c stack_init.c swap_cmd.c error_handler.c \
       ft_split.c push_cmd.c push_swap_cmd.c reverse_rotate_cmd.c small_sort.c stack_utils.c
	
OBJ = $(SRCS:.c=.o)

CC = cc 

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean