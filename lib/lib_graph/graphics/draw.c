/*
** draw.c for graph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/graphics/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 22 15:07:27 2016 Arthur Baurens
** Last update Wed May 24 16:34:21 2017 Arthur Baurens
*/

#include <math.h>
#include "libgraph.h"

void		place_pixel(t_prog *prog, int x, int y, sfColor color)
{
  sfUint8	*pixels;

  pixels = prog->pix;
  if (x < 0 || y < 0 || x >= prog->w || y >= prog->h)
    return ;
  pixels[4 * (x + y * prog->w) + 0] = color.r;
  pixels[4 * (x + y * prog->w) + 1] = color.g;
  pixels[4 * (x + y * prog->w) + 2] = color.b;
  pixels[4 * (x + y * prog->w) + 3] = color.a;
}

void		my_draw_square(t_prog *prog, t_vec2i from,
			       t_vec2i size, sfColor c)
{
  t_vec2i	pos;

  pos.y = -1;
  while (++pos.y < size.y)
    {
      pos.x = -1;
      while (++pos.x < size.x)
	place_pixel(prog, from.x + pos.x, from.y + pos.y, c);
    }
}
