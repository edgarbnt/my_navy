##
## EPITECH PROJECT, 2024
## B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
## File description:
## Makefile
##

SRC	=	src/map_in_array.c \
		src/handle_signals.c \
		src/send_and_received_signals_connection.c \
		src/extract_input_user.c \
		src/receive_attaks_signals.c \
		src/send_signal_attaks.c \
		src/attack_or_wait.c \
		src/interpret_signals_attaks.c \
		src/map_dump.c \
		src/check_hit.c \
		src/check_lose.c \
		include/my_str_to_word_array.c \
		include/my_pow.c \
		src/error_handling_attaks.c \

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-Wextra -Wall -Werror

NAME	=	my_navy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) -Wextra -Werror -Wall -Llib -lmy

clean:
	make -C lib/ clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib/ fclean
	rm -f $(NAME)

re:	fclean all
