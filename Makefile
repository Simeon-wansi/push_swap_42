NAME = push_swap

OPERATIONS_DIR = ./operations
SORTING_DIR = ./sorting_files

OPERATIONS_SRCS = $(addprefix $(OPERATIONS_DIR)/, push_cmd.c reverse_rotate_cmd.c rotate_cmd.c swap_cmd.c)
SORTING_SRCS = $(addprefix $(SORTING_DIR)/, error_handler.c main.c push_swap_init.c stack_init.c \
		ft_split.c push_swap_cmd.c small_sort.c stack_utils.c)

SRCS = $(OPERATIONS_SRCS) $(SORTING_SRCS)
	
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

.PHONY: all clean fclean re