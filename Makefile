##
## Makefile for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/
##
## Made by Julien Delane
## Login   <Realague@epitech.net>
##
## Started on  Mon May 22 10:24:51 2017 Julien Delane
## Last update Sun May 28 19:13:00 2017 Julien Delane
##

MAKE	=	make --no-print-directory -C

CC	=	gcc

NAME	=	raytracer2

SRC	=	src/help.c					\
		src/main.c					\
		src/display/my_rand.c				\
		src/display/color.c				\
		src/architecture/inputs.c			\
		src/architecture/options.c			\
		src/architecture/threading.c			\
		src/architecture/multithreading.c		\
		src/architecture/math_utils.c			\
		src/display/raytracing_core.c 			\
		src/display/output.c				\
		src/display/obj_functions/vector.c		\
		src/display/obj_functions/a_light.c		\
		src/display/obj_functions/calc_dir_vector.c	\
		src/display/obj_functions/intersect.c		\
		src/display/obj_functions/rotation.c		\
		src/display/obj_functions/rotate.c		\
		src/display/obj_functions/translation.c		\
		src/display/effects/texturing.c			\
		src/display/effects/anti_aliasing.c		\
		src/display/effects/shadow.c			\
		src/display/effects/transparency.c		\
		src/display/effects/reflection.c		\
		src/display/effects/direct_light.c		\
		src/display/utils.c				\
		src/parse/bmp/loader_bmp.c			\
		src/parse/bmp/export_bmp.c			\
		src/parse/free.c				\
		src/parse/option_function.c			\
		src/parse/apply_rot_translate.c			\
		src/parse/list_to_tab.c				\
		src/parse/parse_option.c			\
		src/parse/obj/set_rot.c				\
		src/parse/obj/set_quad.c			\
		src/parse/obj/set_pos.c				\
		src/parse/obj/set_mat.c				\
		src/parse/obj/set_color.c			\
		src/parse/obj/set_mapping.c			\
		src/parse/mat/set_transparency.c		\
		src/parse/mat/set_texture.c			\
		src/parse/mat/set_tex_coef.c			\
		src/parse/mat/set_shine.c			\
		src/parse/mat/set_refract.c			\
		src/parse/mat/set_reflect.c			\
		src/parse/light/set_pos.c			\
		src/parse/light/set_intensity.c			\
		src/parse/light/set_color.c			\
		src/parse/what_to_do.c				\
		src/parse/set_obj.c				\
		src/parse/set_mat.c				\
		src/parse/set_light.c				\
		src/parse/print_scene.c				\
		src/parse/parse.c				\
		src/parse/create_obj.c				\
		src/parse/create_mat.c				\
		src/parse/create_light.c			\
		src/parse/check/check.c				\
		src/parse/check/light.c				\
		src/parse/check/mat.c				\
		src/parse/check/mat_opt.c			\
		src/parse/check/obj.c				\
		src/parse/check/obj_mapping.c			\
		src/parse/check/obj_opt.c

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-I./include

CFLAGS	+=	$(INCLUDE) -W -Wall -Wextra

$(NAME):	cmpile_lib $(OBJ)
		$(CC) -o $(NAME) -L./lib/ $(OBJ) -lm -lbs -lmy_printf -lgnl -lpthread -lc_graph_prog -lmygraph

all:	$(NAME)

cmpile_lib:
	$(MAKE) ./lib/lib_graph/
	$(MAKE) lib/lib_benjaminsolca/

clean:
	rm -rf $(OBJ)
	$(MAKE) ./lib/lib_graph/ clean
	$(MAKE) ./lib/lib_benjaminsolca/ clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) ./lib/lib_graph/ fclean
	$(MAKE) ./lib/lib_benjaminsolca/ fclean

relib:
	$(MAKE) ./lib/lib_graph/ re
	$(MAKE) ./lib/lib_benjaminsolca/ re

re:	fclean all

d:	re
d:	CFLAGS += -g
d:	clean

.PHONY:	all clean fclean re d
.SILENT:
