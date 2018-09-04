##
## Makefile for wireframe in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sun Nov 20 10:46:53 2016 Arthur Baurens
## Last update Fri May 12 15:54:52 2017 Julien Delane
##

CC		=	gcc

NAME	=	libmygraph.a

SRC	=	lib_graph_settings.c		\
		lib_graph_frame.c		\
		lib_graph_color.c		\
		lib_graph_loop.c		\
		graphics/draw.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include

CFLAGS	+=	$(INCLUDE) -W -Wall -Werror

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp -rf $(NAME) ../
	cp -rf ./include/* ../../include/

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)
	rm -rf ../include/libgraph.h

re:	fclean all

.PHONY:	all clean fclean re
