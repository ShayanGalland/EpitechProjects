SRC	=	./src/

NAME	=	groundhog

$(NAME)	:
			cp $(SRC)groundhog.py ./
			mv groundhog.py groundhog
			chmod +x groundhog

all	:	$(NAME)

clean:
		rm -rf groundhog

fclean:	clean

re	:	fclean all

.PHONY: all clean fclean re