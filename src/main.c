/*
** main.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 24 14:44:39 2017 Arthur Baurens
** Last update Sun May 28 19:19:23 2017 Benjamin
*/

#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libgraph.h"
#include "rt.h"
#include "bs.h"

void	my_pre(t_prog *prog)
{
  pthread_mutex_init(&((t_rt *)prog->data)->start_mutex, NULL);
  pthread_mutex_init(&((t_rt *)prog->data)->render_mutex, NULL);
}

void	p_bin(unsigned int nbr)
{
  char	v;

  if (nbr / 2 > 0)
    p_bin(nbr / 2);
  v = nbr % 2 + '0';
  write(1, &v, 1);
}

void		my_event(t_prog *prog)
{
  sfVector2i	pos;

  pos = sfMouse_getPositionRenderWindow(prog->wind);
  if (!sfRenderWindow_hasFocus(prog->wind) || pos.y < 0 ||
      pos.y >= prog->h || pos.x < 0 || pos.x >= prog->w)
    return ;
  if (pause_handeling(prog))
    return ;
  controls(prog);
}

void	my_loop(t_prog *prog)
{
  t_rt	*rt;
  char	r;

  rt = (t_rt *)prog->data;
  my_event(prog);
  if (rt->modes & M_PAUSE)
    return ;
  if (!sfRenderWindow_hasFocus(prog->wind))
    set_paused(prog, 1);
  if (!(r = is_same_pos(prog, rt)))
    clear_screen(prog, sfBlack);
  if (!r || rt->old_render != rt->render_mode)
    {
      thread_screen(prog);
      if (rt->render_mode == R_CLASIC)
	write(2, "Rendered!\n", 10);
    }
  rt->old_render = rt->render_mode;
  rt->old_rot = rt->rot;
  reset_trigers(prog);
}

int		main(int ac, char **av)
{
  t_prog	prog;
  char		trig[3];
  t_rt		rt;
  t_parse	parse;
  t_scene	scene;

  if (check_arg(ac, av) == -1)
    return (0);
  my_memset(trig, 0, 3);
  if (ac <= 1 || parse_file(ac, av, &parse, &scene)
      || parse_option(&scene, av, 0) == 84 || list_to_tab(&scene) == -1)
    return (84);
  rt.old_rot = rt.rot;
  rt.old_render = R_DEBUG;
  rt.render_mode = R_DEBUG;
  rt.scene = &scene;
  prog.data = &rt;
  prog.triggers = trig;
  rt.modes = 0 | M_PAUSE;
  new_window("Raytracer 2", 1280, 720, &prog);
  set_pre(&prog, &my_pre);
  set_loop(&prog, &my_loop);
  start_loop(&prog);
  free_scene(&scene);
  return (0);
}
