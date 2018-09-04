/*
** intersect.c for intersect in /home/Realague/Delivery/B_MUL/raytracer2/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Tue Apr 25 17:18:19 2017 Julien Delane
** Last update Sun May 28 18:56:28 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

static t_vec3f		calc_abc(t_quadra quad, t_vec3f dir, t_vec3f eye)
{
  t_vec3f		abc;

  abc.x = quad.a * dir.x * dir.x
    + quad.c * dir.y * dir.y
    + quad.b * dir.z * dir.z
    + quad.d * dir.y * dir.z
    + quad.e * dir.x * dir.z
    + quad.f * dir.x * dir.y;
  abc.y = 2 * (quad.a * eye.x * dir.x + quad.c
	       * eye.y * dir.y + quad.b * eye.z * dir.z)
    + quad.d * (eye.y * dir.z + eye.z * dir.y)
    + quad.e * (eye.x * dir.z + eye.z * dir.x)
    + quad.f * (eye.x * dir.y + eye.y * dir.x)
    + quad.g * dir.x + quad.h * dir.y + quad.i * dir.z;
  abc.z = quad.a * eye.x * eye.x + quad.c * eye.y * eye.y
    + quad.b * eye.z * eye.z
    + quad.d * eye.y * eye.z + quad.e * eye.x * eye.z
    + quad.f * eye.x * eye.y
    + quad.g * eye.x + quad.h * eye.y + quad.i * eye.z + quad.j;
  return (abc);
}

double		intersect(t_quadra quad, t_vec3f dir, t_vec3f eye)
{
  t_vec3f	abc;
  double	delta;
  double	x;
  double	y;

  abc = calc_abc(quad, dir, eye);
  delta = abc.y * abc.y - 4 * abc.x * abc.z;
  if (delta > 0)
    {
      x = (-abc.y - sqrt(delta)) / (2 * abc.x);
      y = (-abc.y + sqrt(delta)) / (2 * abc.x);
      if (x < 0 && y < 0)
	return (-1);
      else if (x >= 0 && y >= 0)
	return ((x > y ? y : x));
      else
        return ((y >= 0 ? y : x));
    }
  else if (!delta && -abc.y / (2 * abc.x) >= 0)
    return (-abc.y / (2 * abc.x));
  else
    return (-1);
}

t_vec3f		calc_normal_vector(t_quadra quad, t_vec3f point)
{
  t_vec3f	normal;

  normal.x = 2 * quad.a * point.x + quad.e * point.z + quad.f * point.y
    + quad.g;
  normal.y = 2 * quad.c * point.y
    + quad.d * point.z + quad.f * point.x + quad.h;
  normal.z = 2 * quad.b * point.z + quad.d * point.y
    + quad.e * point.x + quad.i;
  normalize(&normal);
  return (normal);
}
