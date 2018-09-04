/*
** lib_graph.c for lib_graph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 21 16:28:50 2016 Arthur Baurens
** Last update Tue Dec 13 10:26:36 2016 Arthur Baurens
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "libgraph.h"

static sfRenderWindow		*create_window(t_prog *prog)
{
  sfVideoMode		view;
  sfWindowStyle		style;

  style = sfDefaultStyle;
  if (IMG_ONLY)
    style = sfNone;
  else if (!RESIZABLE && CLOSABLE)
    style = sfClose;
  else if (!CLOSABLE && RESIZABLE)
    style = sfResize;
  else if (!CLOSABLE && !RESIZABLE)
    style = sfTitlebar;
  view.width = prog->w;
  view.height = prog->h;
  view.bitsPerPixel = 32;
  return (sfRenderWindow_create(view, prog->name, style, NULL));
}

static int	create_pixels(t_prog *prog)
{
  sfSprite_setTexture(prog->sprite, prog->tex, sfTrue);
  if ((prog->pix = malloc(prog->w * prog->h * 4 * sizeof(*prog->pix))) == NULL)
    return (1);
  clear_screen(prog, sfBlack);
  return (0);
}

int	new_window(const char *name, int w, int h, t_prog *prog)
{
  prog->w = w;
  prog->h = h;
  prog->name = name;
  prog->pre_fct = NULL;
  prog->loop_fct = NULL;
  prog->event_fct = NULL;
  if ((prog->wind = create_window(prog)) == NULL)
    return (-1);
  prog->sprite = sfSprite_create();
  prog->tex = sfTexture_create(prog->w, prog->h);
  create_pixels(prog);
  sfRenderWindow_setFramerateLimit(prog->wind, 60);
  return (1);
}

void		clear_screen(t_prog *prog, sfColor color)
{
  int		x;
  int		y;
  sfUint8	*pixels;

  x = 0;
  pixels = prog->pix;
  while (x < prog->w)
    {
      y = 0;
      while (y < prog->h)
	{
          pixels[4 * (x + y * prog->w) + 0] = color.r;
          pixels[4 * (x + y * prog->w) + 1] = color.g;
          pixels[4 * (x + y * prog->w) + 2] = color.b;
          pixels[4 * (x + y * prog->w) + 3] = color.a;
	  y++;
	}
      x++;
    }
}
