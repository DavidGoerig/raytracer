/*
** reflection.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/effects/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Sat May 13 16:19:34 2017 Julien Delane
** Last update Thu May 25 15:38:57 2017 Julien Delane
*/

#include "rt.h"

void		reflection(t_rt *rt, t_result *res)
{
  t_result	result;
  double	reflect;

  reflect = res->obj->mat->reflect;
  if (reflect == 0)
    return ;
  result.i = res->i;
  result.camera = res->intersect;
  result.obj = res->obj;
  normalize(&res->dir_vector);
  fill_result(rt, &result, my_reflect(&res->dir_vector, res->normal));
  res->color.r = res->color.r * (1 - reflect) + result.color.r * reflect;
  res->color.g = res->color.g * (1 - reflect) + result.color.g * reflect;
  res->color.b = res->color.b * (1 - reflect) + result.color.b * reflect;
}
