/*
** direct_light.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/effects/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Tue May  9 17:20:49 2017 Julien Delane
** Last update Wed May 24 19:03:10 2017 Julien Delane
*/

#include <stdlib.h>
#include "libgraph.h"
#include "rt.h"

void		direct_light(t_rt *rt, t_result *res,
			     t_light *light, t_vec3f dir_vector)
{
  t_vec3f	light_vector;
  double	coef;
  double	shadow;

  light_vector = get_dir_vector(res->camera, light->pos, 0);
  shadow = check_in_front(rt->scene, light_vector, res->camera);
  normalize(&light_vector);
  if ((coef = dot(dir_vector, light_vector)) < 0)
    coef = 0;
  coef = pow(coef, light->intensity) * shadow;
  res->color.r = res->color.r * (1 - coef) + light->color.r * coef;
  res->color.g = res->color.g * (1 - coef) + light->color.g * coef;
  res->color.b = res->color.b * (1 - coef) + light->color.b * coef;
}

void	add_direct_light(t_scene *scene, t_result *res,
			 t_rt *rt, t_vec3f dir_vector)
{
  int	i;

  i = -1;
  while (++i != scene->nb_light)
    direct_light(rt, res, &scene->light[i], dir_vector);
}
