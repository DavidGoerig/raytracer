/*
** trans.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/effects/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Sat May 13 16:44:05 2017 Julien Delane
** Last update Sun May 28 18:55:30 2017 Julien Delane
*/

#include "rt.h"

static t_vec3f	get_refraction(t_vec3f n, t_vec3f v, double nb)
{
  t_vec3f	vector;
  double	o;
  double	lenght;

  o = nb / 1.000293;
  normalize(&v);
  normalize(&n);
  lenght = sqrt(v.x * v.x + v.y * v.y + v.z * v.z)
    * sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
  vector.x = o * v.x + (o * lenght -
			sqrt(1 + o * o * ((lenght * lenght) - 1))) * n.x;
  vector.y = o * v.y + (o * lenght -
			sqrt(1 + o * o * ((lenght * lenght) - 1))) * n.y;
  vector.z = o * v.z + (o * lenght -
			sqrt(1 + o * o * ((lenght * lenght) - 1))) * n.z;
  return (vector);
}

void		refraction(t_rt *rt, t_result *res)
{
  t_result	result;
  t_vec3f	dir_vector;
  double	trans;

  trans = res->obj->mat->transparency;
  if (trans == 0)
    return ;
  dir_vector = get_refraction(res->normal, res->dir_vector,
			      res->obj->mat->refract);
  result.i = res->i;
  result.camera = res->intersect;
  result.obj = res->obj;
  fill_result(rt, &result, dir_vector);
  res->color.r = result.color.r * trans + res->color.r * (1 - trans);
  res->color.g = result.color.g * trans + res->color.g * (1 - trans);
  res->color.b = result.color.b * trans + res->color.b * (1 - trans);
}
