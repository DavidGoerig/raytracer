/*
** color.c for wolf in /home/baurens/Work/Tek1/Projects/IGRAPH/wolf3d/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Dec 13 12:17:27 2016 Arthur Baurens
** Last update Tue Dec 13 12:25:15 2016 Arthur Baurens
*/

#include <SFML/Graphics/Texture.h>
#include "libgraph.h"

void		set_color(sfColor *color, unsigned int argb)
{
  t_color	tmp;

  tmp.hex = argb;
  color->a = tmp.rgba[0];
  color->r = tmp.rgba[1];
  color->g = tmp.rgba[2];
  color->b = tmp.rgba[3];
}
