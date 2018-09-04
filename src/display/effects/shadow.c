/*
** shadow.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May  1 15:30:20 2017 Julien Delane
** Last update Wed May 24 17:34:11 2017 Julien Delane
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libgraph.h"
#include "rt.h"

int		check_in_front(t_scene *scene, t_vec3f dir, t_vec3f camera)
{
  double	distance;
  double	coef;
  int		i;

  coef = 1;
  distance = -1;
  i = -1;
  while (++i != scene->nb_obj && coef > 0)
    {
      distance = intersect(scene->obj[i].quadra, dir, camera);
      if (distance <= 1 && distance >= 0)
	coef -= (1 - scene->obj[i].mat->transparency);
    }
  return (coef);
}
