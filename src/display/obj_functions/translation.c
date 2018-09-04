/*
** translation.c for raytracer2 in /home/Realague/Delivery/B_MUL/raytracer2/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Wed Apr 26 10:03:26 2017 Julien Delane
** Last update Sun May 28 18:57:28 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

void	translate(t_quadra *quad, t_vec3f tr)
{
  t_quadra	old;

  old = *quad;
  quad->g = -2 * old.a * tr.x - old.e * tr.z - old.f * tr.y + old.g;
  quad->h = -2 * old.c * tr.y - old.d * tr.z - old.f * tr.x + old.h;
  quad->i = -2 * old.b * tr.z - old.d * tr.y - old.e * tr.x + old.i;
  quad->j = old.a * tr.x * tr.x + old.c * tr.y * tr.y + old.b * tr.z * tr.z
    + old.d * tr.y * tr.z + old.e * tr.x * tr.z + old.f * tr.x * tr.y -
    old.g * tr.x - old.h * tr.y - old.i * tr.z + old.j;
}
