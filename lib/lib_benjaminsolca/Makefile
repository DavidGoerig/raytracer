##
## Makefile for lib in /home/benjamin/Dropbox/lib/
##
## Made by Benjamin
## Login   <benjamin.solca@epitech.eu>
##
## Started on  Wed Apr  5 11:14:13 2017 Benjamin
## Last update Mon May 22 09:50:59 2017 Julien Delane
##

RM	=	rm -rf

MAKE	=	make --no-print-directory -C

all:
		/bin/echo -e "\n\x1b[1m\x1b[40m==> COMPILE LIB <==\x1b[0m\n"
		/bin/echo -e "\x1b[1m\x1b[37m** Compiling lib: MY **\x1b[0m"
		make -sC my
		/bin/echo -e "\x1b[32m  -Complete-\x1b[0m"
		/bin/echo -e "\x1b[1m\x1b[37m** Compiling lib: MY_PRINTF **\x1b[0m"
		make -sC my_printf
		/bin/echo -e "\x1b[32m  -Complete-\x1b[0m"
		/bin/echo -e "\x1b[1m\x1b[37m** Compiling lib: GNL **\x1b[0m"
		make -sC gnl
		/bin/echo -e "\x1b[32m  -Complete-\x1b[0m"

d:		CFLAGS += -g -Wall -pedantic
d:		re

clean:
		$(MAKE) my clean
		$(MAKE) gnl clean
		$(MAKE) my_printf clean

fclean:		clean
		$(MAKE) my fclean
		$(MAKE) gnl fclean
		$(MAKE) my_printf fclean

re: 		fclean all

.SILENT:	all debug clean fclean
.PHONY:		all debug clean fclean re
