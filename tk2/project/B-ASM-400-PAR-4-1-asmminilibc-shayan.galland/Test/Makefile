SRC = 	my_strlen.asm 		\
		my_strchr.asm		\
		my_strrchr.asm		\
		my_memset.asm		\
		my_memcpy.asm		\
		my_strcmp.asm		\
		my_memmove.asm		\
		my_strncmp.asm		\
		my_strcasecmp.asm	\
		my_strstr.asm		\
		my_strpbrk.asm		\
		my_strcspn.asm

NAME = libasm.so

all: $(NAME) test

exp:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

OBJ = $(SRC:.asm=.o)

$(OBJ): %.o: %.asm
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJ)
	ld -shared -o $(NAME) $(OBJ)

test: $(NAME) test.c
	gcc -o test test.c -L. -lasm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all