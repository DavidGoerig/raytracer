/*
** math_utils.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/src/architecture/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue May 23 13:32:21 2017 Arthur Baurens
** Last update Tue May 23 13:38:13 2017 Arthur Baurens
*/

#include "parse.h"
#include "rt.h"

float	dot(t_vec3f v1, t_vec3f v2)
{
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3f		my_reflect(t_vec3f *dir, t_vec3f normal)
{
  t_vec3f	result;
  float		d;

  d = dot(*dir, normal);
  result.x = (dir->x - (normal.x * (d * 2)));
  result.y = (dir->y - (normal.y * (d * 2)));
  result.z = (dir->z - (normal.z * (d * 2)));
  return (result);
}

t_vec3f	*negate_vec(t_vec3f *v)
{
  v->x *= -1;
  v->y *= -1;
  v->z *= -1;
  return (v);
}

float	clamp(float min, float val, float max)
{
  if (val < min)
    return (min);
  if (val > max)
    return (max);
  return (val);
}
