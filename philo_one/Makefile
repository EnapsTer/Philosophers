NAME		= philo_one
#####################################sources#######################################

INIT		=	srcs/initialization
PHILOS		=	srcs/philosophers
SIM			=	srcs/simulation
UTILS		=	srcs/utils
DESTROY		=	srcs/destroy
SRC			=	srcs/main.c\
				$(INIT)/config_initialization.c\
				$(INIT)/philosophers_initialization.c\
				$(INIT)/simulation_initialization.c\
				$(PHILOS)/philosophers_live.c\
				$(PHILOS)/philosophers_threads.c\
				$(SIM)/simulation.c\
				$(DESTROY)/destroy.c\
				$(UTILS)/initialization_utils.c\
				$(UTILS)/utils.c\
				$(UTILS)/libft.c

#####i################################objects#######################################
OBJ			= $(SRC:.c=.o)
#####################################flags#######################################
CFLAGS		= -Wall -Wextra -Werror
SANITIZE	= -fsanitize=address
#####################################headers#######################################
INC			= includes/

.c.o:
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