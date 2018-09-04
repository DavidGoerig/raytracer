/*
** lib_graph_loop.c for lib_graph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 21 16:36:18 2016 Arthur Baurens
** Last update Mon May 22 10:16:13 2017 Julien Delane
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "libgraph.h"

static void	lib_event(t_prog *prog)
{
  if (sfRenderWindow_pollEvent(prog->wind, &prog->event))
    {
      if (prog->event.type == sfEvtClosed ||
	  sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(prog->wind);
      if (prog->event_fct != NULL)
	prog->event_fct(prog);
    }
}

void	refresh_window(t_prog *prog)
{
  sfTexture_updateFromPixels(prog->tex, prog->pix, prog->w, prog->h, 0, 0);
  sfRenderWindow_clear(prog->wind, sfBlack);
  sfRenderWindow_drawSprite(prog->wind, prog->sprite, NULL);
  sfRenderWindow_display(prog->wind);
}

void	start_loop(t_prog *prog)
{
  if (prog->pre_fct != NULL)
    prog->pre_fct(prog);
  while (sfRenderWindow_isOpen(prog->wind))
    {
      lib_event(prog);
      if (prog->loop_fct != NULL)
	prog->loop_fct(prog);
      refresh_window(prog);
    }
  free(prog->pix);
  sfSprite_destroy(prog->sprite);
  sfTexture_destroy(prog->tex);
  sfRenderWindow_destroy(prog->wind);
}
