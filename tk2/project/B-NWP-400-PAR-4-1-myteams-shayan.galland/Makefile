##
## EPITECH PROJECT, 2021
## Main Makefile
## File description:
## Main Makefile for client and server
##

.PHONY: client serveur

all: client serveur

client:
	$(MAKE) -C client/

serveur:
	$(MAKE) -C serveur/

clean:
	$(MAKE) clean -C client/
	$(MAKE) clean -C serveur/

fclean: clean
	$(MAKE) fclean -C client/
	$(MAKE) fclean -C serveur/

re: fclean all

##export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs/myteams