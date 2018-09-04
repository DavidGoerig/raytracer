/*
** true_light.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/src/display/obj_functions/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon May 22 16:04:44 2017 Arthur Baurens
** Last update Sun May 28 18:34:34 2017 Julien Delane
*/

#include <stdlib.h>
#include "parse.h"
#include "rt.h"

void		get_specular(t_result *res, t_light *li, t_vec3f l, float d)
{
  t_vec3f	reflect;

  reflect = my_reflect(negate_vec(&l), res->normal);
  d *= pow(dot(reflect, res->dir_vector), res->obj->mat->shine);
  res->specular.x += (float)li->color.r * d;
  res->specular.y += (float)li->color.g * d;
  res->specular.z += (float)li->color.b * d;
}

float		get_diffuse(t_light *li, t_vec3f *di, float d)
{
  di->x += ((float)li->color.r / 255.0) * d;
  di->y += ((float)li->color.g / 255.0) * d;
  di->z += ((float)li->color.b / 255.0) * d;
  return (d);
}

float		cast_shadow(t_rt *rt, t_result *res, t_vec3f l, float d)
{
  int		i;
  t_result	r;
  float		result;
  t_vec3f	random;
  t_vec3f	ray_dir;

  i = -1;
  result = 0;
  while (rt->render_mode == R_CLASIC && ++i < rt->scene->option->shadow)
    {
      random = vec3_random();
      ray_dir = l;
      if (rt->scene->option->shadow > 1)
	v_add(&ray_dir, &random, 0.04);
      if ((r = collide(rt, &res->intersect, &ray_dir, &r)).dist != -1 &&
	  r.dist < d)
        result++;
    }
  return (1.0 - (result / (float)rt->scene->option->shadow));
}

t_vec3f		get_lights_color(t_rt *rt, t_result *res)
{
  int		i;
  float		d;
  float		light_dist;
  t_vec3f	light_dir;
  t_vec3f	coef;

  i = -1;
  coef = rt->scene->option->ambient;
  res->specular = (t_vec3f){0, 0, 0};
  while (++i < rt->scene->nb_light)
    {
      light_dir = rt->scene->light[i].pos;
      v_add(&light_dir, &res->intersect, -1);
      light_dist = norme(&light_dir);
      normalize(&light_dir);
      d = clamp(0, dot(light_dir, res->normal), 1);
      d *= cast_shadow(rt, res, light_dir, light_dist);
      get_diffuse(&rt->scene->light[i], &coef, d);
      if (rt->render_mode != R_DEBUG)
	get_specular(res, &rt->scene->light[i], light_dir, d);
    }
  coef.x = clamp(0, coef.x, 1);
  coef.y = clamp(0, coef.y, 1);
  coef.z = clamp(0, coef.z, 1);
  return (coef);
}

void		apply_lights_effects(t_rt *rt, t_result *res)
{
  t_vec3f	coef;

  coef = get_lights_color(rt, res);
  res->color.a = 255;
  res->color.r *= coef.x;
  res->color.g *= coef.y;
  res->color.b *= coef.z;
  if (rt->render_mode == R_DEBUG)
    return ;
  res->color.r = clamp(0, res->color.r + res->specular.x, 255);
  res->color.g = clamp(0, res->color.g + res->specular.y, 255);
  res->color.b = clamp(0, res->color.b + res->specular.z, 255);
}
