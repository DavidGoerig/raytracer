/*
** check.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 18 13:00:01 2017 Benjamin
** Last update Sat May 27 16:25:50 2017 Benjamin
*/

#include "parse.h"

int		check_parse(char **tab, t_scene *scene)
{
  t_scene	*tmp;

  tab = tab;
  tmp = scene;
  check_light(tmp->light);
  tmp = scene;
  check_mat(tmp->mat);
  tmp = scene;
  return (check_obj(tmp->obj, tmp->mat));
}
