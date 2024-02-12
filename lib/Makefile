##
## EPITECH PROJECT, 2024
## lib
## File description:
## Makefile
##

SRC	=	my_bzero.c \
		my_getnbr.c \
		my_nb_to_str.c \
		my_putnbr.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isupper.c \
		my_str_to_word_array.c \
		my_strcat.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_revstr.c \
		my_strlowcase.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strcmp.c \
		my_atoi.c \
		my_strupcase.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
