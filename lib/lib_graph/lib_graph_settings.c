/*
** lib_graph_settings.c for lib_graph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 21 17:03:15 2016 Arthur Baurens
** Last update Mon Nov 21 17:31:35 2016 Arthur Baurens
*/

#include "libgraph.h"

void	set_pre(t_prog *prog, void (*func)(t_prog *))
{
  prog->pre_fct = func;
}

void	set_loop(t_prog *prog, void (*func)(t_prog *))
{
  prog->loop_fct = func;
}

void	set_event(t_prog *prog, void (*func)(t_prog *))
{
  prog->event_fct = func;
}

void	set_all_func(t_prog *prog, void (*pre)(t_prog *),
		     void (*loop)(t_prog *),
                     void (*event)(t_prog *))
{
  prog->pre_fct = pre;
  prog->loop_fct = loop;
  prog->event_fct = event;
}
