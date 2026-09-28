NAME      = Colleen

CC        = cc
CFLAGS    = -Wall -Werror -Wextra -g3

OBJ_DIR   = .obj

SRC_FILES  = main.c

OBJS      := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 