##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for SYN_palindrome_2017
##

SRC		=	src/main.c				\
			src/core/tree/dir_parsing.c		\
			src/core/tree/file_parsing.c		\
			src/core/tree/list_parsing.c		\
			src/core/utils/free_nodes.c		\
			src/core/utils/free_explorer.c		\
			src/core/utils/free_tab.c		\
			src/core/utils/getpwd.c			\
			src/core/utils/init_explorer.c		\
			src/gui/utils/middle_print.c		\
			src/gui/gui_main.c			\
			src/keyboard/keyboard_handler.c		\

SRCS_TEST	=

OBJ		=	$(SRC:.c=.o)

INC_DIR		=	$(realpath ./include)

LIB_DIR		=	$(realpath ./lib)

NAME		=	explorer

NAME_LIBMY	=	lib/libmy.a

NAME_TEST_LIB	=	lib/libtestmy.a

CFLAGS		=	-W -Wall -Wextra -Wc99-c11-compat -pedantic \
			-std=c99 -I$(INC_DIR) -g3

LDFLAGS		=	-L$(LIB_DIR) -lmy -lncurses

LDTESTFLAGS	=	-L$(LIB_DIR) -ltestmy -lncurses

all:		$(NAME_LIBMY) $(NAME)

$(NAME_TEST_LIB):
		make all clean -C ./lib/testmy

$(NAME_LIBMY):
		make all clean -C ./lib/my

$(NAME):	$(OBJ)
		gcc -o	$(NAME)	$(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C ./lib/my
		make clean -C ./lib/testmy
		rm -f *.gc*
		rm -f vgcore.*

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./lib/my
		make fclean -C ./lib/testmy
		rm -f units
		rm -rf ./report
		rm -f rapport.info

re:		fclean all

tests_run:	$(NAME_TEST_LIB) $(SRCS_TEST)
		gcc $(SRCS_TEST) -I./include/ -o units --coverage -lcriterion $(LDTESTFLAGS)
		./units -j0 --always-succeed
		gcov *

tests_coverage:	fclean tests_run
		lcov --directory . -c -o rapport.info
		genhtml -o ./report -t "code coverage report" rapport.info
		xdg-open ./report/index.html &>/dev/null

docker_test:	fclean
		sudo docker run -v `pwd`:/project -it epitechcontent/epitest-docker /bin/bash

.PHONY: all clean fclean re tests_run tests_coverage docker_test
