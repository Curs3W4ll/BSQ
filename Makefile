##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile | https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables
##

CC			= 	gcc

RM			= 	rm -rf

SRC			=	src/main.c 				\
				src/bsq.c 				\
				src/errors.c 			\
				src/read_file.c 		\
				src/allocs.c 			\
				src/tools.c 			\
				src/change_bsq_tests.c 	\
				src/find_bsq.c

OBJ			=	$(SRC:.c=.o)

NAME        =   bsq

TEST_SRC 	= 	src/bsq.c 				\
				src/errors.c 			\
				src/read_file.c 		\
				src/allocs.c 			\
				src/tools.c 			\
				src/change_bsq_tests.c 	\
				src/find_bsq.c 			\
				tests/test.c 			\
				tests/test_output.c 	\
				tests/test_errors.c

CFLAGS		=	-Wall -Werror -Wextra

LDFLAGS		= 	-L./lib -lmy

CPPFLAGS	=	-I./include

all: 		$(NAME)

$(NAME): 	lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

lib:
	make -C lib/my/

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)
	make -C lib/my/ fclean

re:			fclean all

tests_run: 	re
	# gcc -o unit_tests $(TEST_SRC) $(LDFLAGS) $(CPPFLAGS) --coverage -lcriterion
	# ./unit_tests
	echo "tests_run"

.PHONY: all lib clean fclean re tests_run
