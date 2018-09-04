/*
** options.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 31 14:50:51 2017 Arthur Baurens
** Last update Sun May 28 18:52:58 2017 Julien Delane
*/

#include "rt.h"

void	set_paused(t_prog *prog, char b)
{
  t_rt	*rt;

  rt = (t_rt *)prog->data;
  if (b)
    rt->modes |= M_PAUSE;
  else if ((rt->modes & M_PAUSE) != 0)
    rt->modes -= M_PAUSE;
  sfRenderWindow_setMouseCursorVisible(prog->wind, b);
}

char		pause_handeling(t_prog *prog)
{
  t_rt		*rt;
  sfVector2i	pos;

  rt = (t_rt *)prog->data;
  if (rt->modes & M_PAUSE)
    {
      if (sfMouse_isButtonPressed(0) && !prog->triggers[0])
	{
	  pos = sfMouse_getPositionRenderWindow(prog->wind);
	  prog->triggers[0] = 1;
	  pos.x = prog->w / 2;
	  pos.y = prog->h / 2;
	  set_paused(prog, 0);
	  sfMouse_setPositionRenderWindow(pos, prog->wind);
	}
      return (1);
    }
  if (sfKeyboard_isKeyPressed(sfKeyP))
    set_paused(prog, 1);
  return (0);
}
