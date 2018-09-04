/*
** raytracing_core.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar 30 17:55:31 2017 Arthur Baurens
** Last update Sun May 28 18:40:15 2017 Julien Delane
*/

#include <stdio.h>
#include <math.h>
#include "libgraph.h"
#include "rt.h"

t_result	collide(t_rt *rt, t_vec3f *ori, t_vec3f *dir, t_result *res)
{
  int		i;
  float		d;
  t_obj		*o;

  i = -1;
  res->dist = -1;
  while (++i < rt->scene->nb_obj)
    {
      d = intersect(rt->scene->obj[i].quadra, *normalize(dir), *ori);
      if ((d > 0.00001 && (d < res->dist || res->dist == -1)))
	{
	  if (res->i == 0 || !res->obj || res->obj != &rt->scene->obj[i])
	    {
	      res->dist = d;
	      o = &rt->scene->obj[i];
	    }
	}
    }
  res->obj = o;
  return (*res);
}

void	fill_result(t_rt *rt, t_result *res, t_vec3f dir_vector)
{
  res->color = sfBlack;
  res->dir_vector = dir_vector;
  collide(rt, &res->camera, &dir_vector, res);
  if (res->dist == -1)
    return ;
  res->intersect = get_pos_res(res->camera, res->dist, dir_vector);
  res->normal = calc_normal_vector(res->obj->quadra, res->intersect);
  res->color = res->obj->color;
  res->color = get_object_color(rt, res);
  apply_lights_effects(rt, res);
  if (rt->render_mode == R_CLASIC && rt->scene->nb_light > 0 &&
      res->i != rt->scene->option->reflect)
    {
      res->i++;
      reflection(rt, res);
      refraction(rt, res);
    }
}

void		get_pixel_color(t_prog *prog, t_vec2i pos)
{
  t_rt		*rt;
  t_vec2i	s_s;
  t_vec3f	dir_vector;
  t_result	res;

  res.obj = NULL;
  rt = (t_rt *)prog->data;
  s_s = (t_vec2i){prog->w, prog->h};
  if (rt->scene->option->ssaa > 1 && rt->render_mode)
    return (place_pixel(prog, pos.x, pos.y,
			super_sampling(rt->scene, rt, s_s, pos)));
  res.i = 0;
  dir_vector = calc_dir_vector(s_s, pos);
  dir_vector = rotate_xyz(dir_vector, rt->rot);
  res.camera = rt->pos;
  if (rt->render_mode != R_DEBUG ||
      (pos.x % DEBUG_RES.x == 0 && pos.y % DEBUG_RES.y == 0))
    {
      fill_result(rt, &res, dir_vector);
      if (rt->render_mode)
	add_direct_light(rt->scene, &res, rt, dir_vector);
      my_draw_square(prog, pos, rt->render_mode ? RENDER_RES :
		     DEBUG_RES, res.color);
    }
}
