##
## EPITECH PROJECT, 2021
## dd
## File description:
## dd
##


EXEC            =       my_number.c	\

all:    $(EXEC)

$(EXEC):
	gcc *.c -Wall -Wextra -o $(EXEC)

clean:
	find . \( -name "#*#" -or -name "*~" \
	-or -name "*.gcno" -or -name "*.gcda"  \) -delete

fclean: clean
	rm -f $(EXEC)

re:     fclean all
