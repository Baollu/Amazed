##
## EPITECH PROJECT, 2024
## test
## File description:
## test
##

NAME =		amazed

SRC = 		src/main.c			\
		src/link.c			\
		src/memory.c			\
		src/print_graph.c		\
		src/amazed.c			\
		src/robustness.c		\
		src/args_check.c		\
		src/find_robot_number.c		\
		src/init_robot_info.c		\
		src/check_start_end.c		\
		src/push_to_list.c		\
		src/init_tunnels.c		\
		src/is_room.c			\
		src/push_tunnels.c		\
		src/add_tunnels.c		\
		src/delete_comment.c		\
		src/print_result.c		\
		src/print_shortest_path.c	\
		src/print_path.c		\
		src/my_strcat.c 		\
		src/my_strcpy.c			\
		src/check_room.c		\
		src/check_comment.c		\

OBJ = 		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS = 	-iquote ./include

LD_LIBRARY_PATH = -L.

LDFLAGS  =	-lmy				\

LIB_PATH = 	./lib/my

FLAG_DEBUG = -g3

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LD_LIBRARY_PATH) $(LDFLAGS)

tests_run: $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o tests/unit_tests $(SRC) tests/test_main.c \
	--coverage -lcriterion $(LD_LIBRARY_PATH) $(LDFLAGS) $(CPPFLAGS)

test:
	make re
	./$(NAME) < maps_test/map2.txt

rand:
	make re
	./maps_test/laby_gen.pl 15 12 10 | ./amazed > map
	./bonus/main.py map
	cat map
	rm map

debug:	$(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC) $(LD_LIBRARY_PATH) $(LDFLAGS) $(FLAG_DEBUG) \
	-I include

clean:
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tclean:
	rm -f tests/unit_tests*

re: fclean all

.PHONY: all tests_run test debug clean fclean tclean re rand
