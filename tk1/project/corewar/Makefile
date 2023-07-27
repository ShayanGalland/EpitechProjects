##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME		=	main_Makefile

all:    $(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C asm
	$(MAKE) -C corewar

clean:
	$(RM) -f *.o

fclean: clean
	$(MAKE) fclean -C lib/my
	$(MAKE) fclean -C asm
	$(MAKE) fclean -C corewar

re:     fclean all

.PHONY: all clean fclean re
