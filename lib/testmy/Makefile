##
## EPITECH PROJECT, 2017
## libMy Makefile
## File description:
## Epitech's First Year libMy with unit tests
##

#Répertoire des includes
INC_DIR=	$(realpath ../../include)

#Répertoire du binaire de librairie
LIB_DIR=	$(realpath ../)

#Fichiers header
HEADERS=	include/int.h				\
		include/libmy.h				\
		include/memory.h			\
		include/parsing.h			\
		include/printing.h			\
		include/strings.h			\
		include/tests.h

#Fichiers sources
SRC=		int/my_atoi.c				\
		int/my_isneg.c				\
		int/my_is_prime.c			\
		int/my_itos.c				\
		int/my_sort_int_array.c			\
		int/my_swap_int.c			\
		memory/smalloc.c			\
		parsing/get_next_line.c			\
		parsing/my_str_to_word_array.c		\
		printing/my_printf.c			\
		printing/my_printf_core1.c		\
		printing/my_printf_core2.c		\
		printing/my_putchar.c			\
		printing/my_put_nbr.c			\
		printing/my_putstr.c			\
		strings/my_revstr.c			\
		strings/my_strcapitalize.c		\
		strings/my_strcat.c			\
		strings/my_strcmp.c			\
		strings/my_strcpy.c			\
		strings/my_strdup.c			\
		strings/my_strlen.c			\
		strings/my_strlowcase.c			\
		strings/my_strncat.c			\
		strings/my_strncmp.c			\
		strings/my_strncpy.c			\
		strings/my_strstr.c			\
		strings/my_strtod.c			\
		strings/my_strupcase.c			\
		strings/utils/my_str_isalpha.c		\
		strings/utils/my_str_islower.c		\
		strings/utils/my_str_isnum.c		\
		strings/utils/my_str_isprintable.c	\
		strings/utils/my_str_isupper.c		\
		strings/utils/is_alpha.c		\
		strings/utils/is_num.c

#Fichiers objets
OBJ=		$(SRC:.c=.o)

#Flags de compilation
CFLAGS=		-W -Wall -Wextra -Werror -pedantic -I./include -std=c99

#Nom du binaire
NAME=		libtestmy.a

#Règles
all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../
		cp -f $(HEADERS) $(INC_DIR)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f ../$(NAME)

re:		fclean all
