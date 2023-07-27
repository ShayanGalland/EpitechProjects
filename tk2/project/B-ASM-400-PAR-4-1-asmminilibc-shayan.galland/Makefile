SRC	=	MinilibC/strlen.asm		\
		MinilibC/strchr.asm		\
		MinilibC/memset.asm		\
		MinilibC/memcpy.asm		\
		MinilibC/memmove.asm	\
		MinilibC/strcmp.asm		\
		MinilibC/strncmp.asm	\
		MinilibC/strcasecmp.asm	\
		MinilibC/strstr.asm		\
		MinilibC/strrchr.asm

NAME	=	libasm.so

OBJ	=	$(SRC:.asm=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -nostdlib -shared -fPIC $(OBJ) -o $(NAME)

%.o : %.asm
		nasm -f elf64 -o $@ $<

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all