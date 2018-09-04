/*
** vector.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 31 21:00:07 2017 Arthur Baurens
** Last update Wed May 24 17:26:27 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

float	norme(t_vec3f *v)
{
  return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec3f	*v_add(t_vec3f *v1, t_vec3f *v2, double fact)
{
  v1->x += (v2->x * fact);
  v1->y += (v2->y * fact);
  v1->z += (v2->z * fact);
  return (v1);
}

t_vec3f	*normalize(t_vec3f *v)
{
  float	norm;

  norm = norme(v);
  v->x /= norm;
  v->y /= norm;
  v->z /= norm;
  return (v);
}

t_vec3f		get_dir_vector(t_vec3f a, t_vec3f b, int i)
{
  t_vec3f	dir_vector;

  dir_vector.x = b.x - a.x;
  dir_vector.y = b.y - a.y;
  dir_vector.z = b.z - a.z;
  if (i)
    normalize(&dir_vector);
  return (dir_vector);
}

t_vec3f		get_pos_res(t_vec3f eye_pos, float distance,
			    t_vec3f dir_vector)
{
  t_vec3f	pos;

  pos.x = eye_pos.x + distance * dir_vector.x;
  pos.y = eye_pos.y + distance * dir_vector.y;
  pos.z = eye_pos.z + distance * dir_vector.z;
  return (pos);
}
