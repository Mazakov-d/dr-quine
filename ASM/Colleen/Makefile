NAME      = Colleen

NASM      = nasm
FLAGS     = -f elf64
LD        = ld

OBJ_DIR   = .obj

SRC_FILES = main.asm

OBJS     := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.asm=.o))


all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.asm $(OBJ_DIR)
	$(NASM) $(FLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 