/*
** threading.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar 30 17:34:33 2017 Arthur Baurens
** Last update Sun May 28 18:53:19 2017 Julien Delane
*/

#include <pthread.h>
#include "libgraph.h"
#include "rt.h"

static void	my_thread_wait(t_rt *rt)
{
  pthread_mutex_lock(&rt->start_mutex);
  rt->counter++;
  while (rt->counter < H_SPLIT * W_SPLIT)
    {
      pthread_mutex_unlock(&rt->start_mutex);
      pthread_mutex_lock(&rt->start_mutex);
    }
  pthread_mutex_unlock(&rt->start_mutex);
}

static char	find_slowest_thread(t_thread *this, t_rt *rt)
{
  int		i;
  t_thread	*to_help;

  i = -1;
  to_help = NULL;
  while (++i < W_SPLIT * H_SPLIT)
    {
      pthread_mutex_lock(&rt->threads[i].end_mut);
      if (this != &rt->threads[i] && rt->threads[i].progress >= 5 &&
	  (to_help == NULL || rt->threads[i].progress > to_help->progress))
	to_help = &rt->threads[i];
      pthread_mutex_unlock(&rt->threads[i].end_mut);
    }
  if (to_help == NULL)
    return (0);
  pthread_mutex_lock(&to_help->end_mut);
  pthread_mutex_lock(&this->end_mut);
  this->start.x = to_help->start.x;
  this->start.y = (to_help->end.y - to_help->cur.y) / 2 + to_help->cur.y;
  this->cur = this->start;
  this->end = to_help->end;
  to_help->end.y = this->start.y;
  pthread_mutex_unlock(&this->end_mut);
  pthread_mutex_unlock(&to_help->end_mut);
  return (1);
}

static void	*end_thread(t_rt *rt)
{
  pthread_mutex_lock(&rt->start_mutex);
  rt->counter--;
  pthread_mutex_unlock(&rt->start_mutex);
  return (NULL);
}

void		*thread(void *var)
{
  t_thread	*this;

  this = (t_thread *)var;
  this->loop = 1;
  this->progress = (this->end.y - this->start.y);
  my_thread_wait(this->prog->data);
  while (this->loop && !(this->loop = 0))
    {
      pthread_mutex_lock(&this->end_mut);
      this->cur.y = this->start.y -1;
      while (++this->cur.y < this->end.y)
	{
	  pthread_mutex_unlock(&this->end_mut);
	  pthread_mutex_lock(&this->end_mut);
	  this->cur.x = this->start.x -1;
	  while (++this->cur.x < this->end.x)
	    get_pixel_color(this->prog, this->cur);
	  pthread_mutex_unlock(&this->end_mut);
	  pthread_mutex_lock(&this->end_mut);
	}
      this->progress = (this->end.y - this->cur.y);
      pthread_mutex_unlock(&this->end_mut);
      this->loop = find_slowest_thread(this, (t_rt *)this->prog->data);
    }
  return (end_thread(this->prog->data));
}

void		*refresh_thread(void *data)
{
  t_prog	*prog;
  t_rt		*rt;

  prog = data;
  rt = prog->data;
  pthread_mutex_lock(&rt->start_mutex);
  while (rt->counter > 0)
    {
      pthread_mutex_unlock(&rt->start_mutex);
      if (rt->render_mode == R_CLASIC &&
	  pthread_mutex_trylock(&rt->render_mutex) == 0)
	{
	  refresh_window(prog);
	  pthread_mutex_unlock(&rt->render_mutex);
	}
      pthread_mutex_lock(&rt->start_mutex);
    }
  pthread_mutex_unlock(&rt->start_mutex);
  return (NULL);
}
