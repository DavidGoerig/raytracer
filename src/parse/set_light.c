/*
** set_light.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 13:32:44 2017 Benjamin
** Last update Sun May 28 19:09:25 2017 Julien Delane
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int		set_light(char **tab, char *name, t_light *light, t_parse *parse)
{
  t_light	*tmp;
  int		err;

  tmp = light;
  err = 0;
  while (tmp && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (my_strstr(tab[0], "pos"))
    err += set_light_pos(tmp, tab, parse->line);
  else if (my_strstr(tab[0], "intens"))
    err += set_light_intensity(tmp, tab, parse->line);
  else if (my_strstr(tab[0], "color"))
    err += set_light_color(tmp, tab, parse->line);
  return (err);
}
