/*
** set_obj.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 13:32:44 2017 Benjamin
** Last update Sun May 28 18:40:32 2017 Julien Delane
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_obj(char **tab, char *name, t_obj *obj, t_parse *parse)
{
  int	i;
  t_obj	*tmp;
  char	**model;
  int	(*fnc[7])(t_obj *, char **, int);

  i = -1;
  tmp = obj;
  model = (char *[]){"mat", "quad", "pos", "rot", "color", "map", NULL};
  fnc[0] = set_obj_mat;
  fnc[1] = set_obj_quad;
  fnc[2] = set_obj_pos;
  fnc[3] = set_obj_rot;
  fnc[4] = set_obj_color;
  fnc[5] = set_obj_mapping;
  fnc[6] = NULL;
  while (tmp && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  while (model[++i] != NULL && !my_strstr(tab[0], model[i]));
  if (model[i] != NULL)
    return (fnc[i](tmp, tab, parse->line));
  return (0);
}
