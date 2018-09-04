/*
** set_mapping.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Fri May 26 12:58:57 2017 Benjamin
** Last update Sun May 28 19:06:59 2017 Julien Delane
*/

#include "parse.h"
#include "bs.h"

static t_mapping	mapping(char *str)
{
  if (my_strstr("plane", str))
    return (M_PLANE);
  if (my_strstr("sphere", str))
    return (M_SPHERE);
  if (my_strstr("cylinder", str))
    return (M_CYLINDER);
  return (M_NONE);
}

int	set_obj_mapping(t_obj *obj, char **tab, int nb_line)
{
  if ((tab && cnt_line_tab(tab) > 1 &&
       (obj->mapping = mapping(tab[1])) != M_NONE) ||
      (obj->mat && !obj->mat->texture))
    {
      obj->parse.mapping = 0;
      return (0);
    }
  obj->parse.mapping = nb_line;
  return (1);
}
