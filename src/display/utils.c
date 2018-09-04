/*
** utils.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May  8 11:03:12 2017 Julien Delane
** Last update Thu May 25 09:26:10 2017 Arthur Baurens
*/

#include "libgraph.h"
#include "rt.h"

void	add_int(int *a, int *b)
{
  a[0] += b[0];
  a[1] += b[1];
  a[2] += b[2];
}

void	remove_int(int *a, int b)
{
  a[0] /= b;
  a[1] /= b;
  a[2] /= b;
}

void	add(int *i, sfColor color, double coef)
{
  i[0] += color.r * coef;
  i[1] += color.g * coef;
  i[2] += color.b * coef;
}

void	init_int(int *color, int size)
{
  int		i;

  i = -1;
  while (++i != size)
    color[i] = 0;
}
