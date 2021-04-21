NAME		= philo_one
#####################################sources#######################################
SRC			= main.c
#####i################################objects#######################################
OBJ			= $(SRC:.c=.o)
#####################################flags#######################################
CFLAGS		= -Wall -Wextra  # TODO werror
SANITIZE	= -fsanitize=address
#####################################headers#######################################
INC			= includes/

.c.o: $(HDR)
	gcc $(CFLAGS) -I$(INC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HDR)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette **/*.c
	norminette srcs/**/*.c
	norminette **/*.h

.PHONY: all clean fclean re