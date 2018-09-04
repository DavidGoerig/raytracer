/*
** print_c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 18 13:42:55 2017 Benjamin
** Last update Sun May 28 22:55:25 2017 Benjamin
*/

#include <stdio.h>
#include "parse.h"
#include "my_prtf.h"

static void	print_mat(t_mat *mat)
{
  my_printf(C_YELLOW "\n**************\n***MATERIAL***\n\n");
  while (mat)
    {
      my_printf(C_RED "\nNAME: %s\n", mat->name);
      my_printf(C_CYAN "Transparency:\t" C_END "%d\n", mat->transparency);
      my_printf(C_CYAN "Reflect:\t" C_END "%f\n", mat->reflect);
      my_printf(C_CYAN "Refract:\t" C_END "%f\n", mat->refract);
      my_printf(C_CYAN "Shine:\t\t" C_END "%f\n", mat->shine);
      if (mat->texture)
	my_printf(C_CYAN "Texture:\t" C_END "H: %d W: %d\n",
		  mat->texture->height,
		  mat->texture->width);
      mat = mat->next;
    }
}

static void	print_light(t_light *light)
{
  my_printf(C_YELLOW "\n***************\n*****LIGHT*****\n\n");
  while (light)
    {
      my_printf(C_RED "\nNAME: %s\n", light->name);
      my_printf(C_CYAN "Position:\t" C_END "%f %f %f\n", light->pos.x,
		light->pos.y, light->pos.z);
      my_printf(C_CYAN "Intensity:\t" C_END "%d\n", light->intensity);
      my_printf(C_CYAN "Color:\t\t" C_END "%f %f %f\n", light->color.r,
		light->color.g, light->color.b);
      light = light->next;
    }
}

static void	print_obj(t_obj *obj)
{
  my_printf(C_YELLOW "\n***************\n*****OBJECT****\n\n");
  while (obj)
    {
      my_printf(C_RED "\nNAME: %s\n", obj->name);
      my_printf(C_CYAN "Material Name:\t" C_END "%s\n", obj->mat_name);
      my_printf(C_CYAN "Quadra:\t\t" C_END "%f %f %f %f %f %f %f %f %f %f\n",
		obj->quadra.a,
		obj->quadra.b, obj->quadra.c, obj->quadra.d,
		obj->quadra.e, obj->quadra.f, obj->quadra.g,
		obj->quadra.h, obj->quadra.i, obj->quadra.j);
      my_printf(C_CYAN "Color:\t\t" C_END "%d %d %d\n",
		obj->color.r, obj->color.g, obj->color.b);
      my_printf(C_CYAN "Position:\t" C_END "%f %f %f\n", obj->pos.x,
		obj->pos.y, obj->pos.z);
      my_printf(C_CYAN "Rotation:\t" C_END "%f %f %f\n", obj->rot.x,
		obj->rot.y, obj->rot.z);
      obj = obj->next;
    }
}

void		print_scene(t_scene *scene)
{
  t_scene	*tmp;

  tmp = scene;
  print_mat(tmp->mat);
  print_light(tmp->light);
  print_obj(tmp->obj);
}
