/*
** rotate.c for raytracer in /home/Realague/Delivery/B_MUL/raytracer1/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon Feb 13 20:58:23 2017 Julien Delane
** Last update Sun May 28 18:56:54 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

t_vec3f		v_rotate_x(t_vec3f to_rotate, float x)
{
  t_vec3f	tmp;

  if (x)
    {
      tmp.x = to_rotate.x;
      tmp.y = cos(x) * to_rotate.y + -sin(x) * to_rotate.z;
      tmp.z = sin(x) * to_rotate.y + cos(x) * to_rotate.z;
      return (tmp);
    }
  return (to_rotate);
}

t_vec3f		v_rotate_y(t_vec3f to_rotate, float y)
{
  t_vec3f	tmp;

  if (y)
    {
      tmp.x = cos(y) * to_rotate.x + sin(y) * to_rotate.z;
      tmp.y = to_rotate.y;
      tmp.z = -sin(y) * to_rotate.x + cos(y) * to_rotate.z;
      return (tmp);
    }
  return (to_rotate);
}

t_vec3f		v_rotate_z(t_vec3f to_rotate, float z)
{
  t_vec3f	tmp;

  if (z)
    {
      tmp.x = cos(z) * to_rotate.x + -sin(z) * to_rotate.y;
      tmp.y = sin(z) * to_rotate.x + cos(z) * to_rotate.y;
      tmp.z = to_rotate.z;
      return (tmp);
    }
  return (to_rotate);
}

t_vec3f	rotate_xyz(t_vec3f to_rotate, t_vec3f angles)
{
  to_rotate = v_rotate_x(to_rotate, TO_RAD(angles.z));
  to_rotate = v_rotate_y(to_rotate, TO_RAD(angles.x));
  to_rotate = v_rotate_z(to_rotate, TO_RAD(-angles.y));
  return (to_rotate);
}

t_vec3f	rotate_zyx(t_vec3f to_rotate, t_vec3f angles)
{
  to_rotate = v_rotate_z(to_rotate, TO_RAD(angles.z));
  to_rotate = v_rotate_y(to_rotate, TO_RAD(angles.y));
  to_rotate = v_rotate_x(to_rotate, TO_RAD(angles.x));
  return (to_rotate);
}
