/*
** multithreading.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/src/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon May 22 09:35:06 2017 Arthur Baurens
** Last update Mon May 22 09:35:21 2017 Arthur Baurens
*/

#include <pthread.h>
#include "libgraph.h"
#include "rt.h"

void		thread_screen(t_prog *prog)
{
  int		i;
  t_rt		*rt;
  t_vec2f	ratio;
  pthread_t	refresher;

  i = -1;
  rt = (t_rt *)prog->data;
  rt->counter = 0;
  ratio.x = (double)prog->w / W_SPLIT;
  ratio.y = (double)prog->h / H_SPLIT;
  while (++i < H_SPLIT * W_SPLIT)
    {
      pthread_mutex_init(&(rt->threads[i].end_mut), NULL);
      rt->threads[i].id = i;
      rt->threads[i].prog = prog;
      rt->threads[i].progress = -1;
      rt->threads[i].start.x = (ratio.x * (i % W_SPLIT));
      rt->threads[i].start.y = (ratio.y * (i / W_SPLIT));
      rt->threads[i].cur = rt->threads[i].start;
      rt->threads[i].end.x = (ratio.x * ((i % W_SPLIT) + 1));
      rt->threads[i].end.y = (ratio.y * ((i / W_SPLIT) + 1));
      pthread_create(&(rt->threads[i].thread), NULL, &thread, &rt->threads[i]);
    }
  pthread_create(&refresher, NULL, &refresh_thread, prog);
  pthread_join(refresher, NULL);
}
