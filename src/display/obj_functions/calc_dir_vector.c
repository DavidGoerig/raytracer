/*
** calc_dir_vector.c for raytracer in /home/Realague/Delivery/B_MUL/raytracer1/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Fri Mar 17 09:57:52 2017 Julien Delane
** Last update Sun May 28 18:56:14 2017 Julien Delane
*/

#include <math.h>
#include "libgraph.h"
#include "rt.h"

t_vec3f		calc_dir_vector(t_vec2i screen_size, t_vec2i screen_pos)
{
  t_vec3f	vector;

  vector.x = FOV_F(screen_size.x, FOV);
  vector.y = (screen_size.x / 2) - screen_pos.x;
  vector.z = (screen_size.y / 2) - screen_pos.y;
  normalize(&vector);
  return (vector);
}
