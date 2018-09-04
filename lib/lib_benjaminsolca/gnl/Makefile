##
## Makefile for GNL in /home/benjamin/Dropbox/func/
##
## Made by Benjamin
## Login   <benjamin.solca@epitech.eu>
##
## Started on  Sun Apr  2 19:26:50 2017 Benjamin
## Last update Mon Apr 17 15:49:38 2017 Benjamin
##

RM	=	rm -rf

SRC	=	get_next_line.c		\

NAME	= 	../../libgnl.a

OBJ	= 	$(SRC:.c=.o)

CFLAGS	+=		-I../../../include/

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

d:		CFLAGS += -g -Wall -pedantic
d:		re

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
