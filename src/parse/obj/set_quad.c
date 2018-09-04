/*
** set_quad.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:45:51 2017 Benjamin
** Last update Fri May 26 10:11:43 2017 Benjamin
*/

#include <stdlib.h>
#include "rt.h"
#include "bs.h"

static int	check_quadra(char **tab)
{
  int		i;

  i = 0;
  while (++i < 10)
    {
      if (is_str_num(tab[i]))
	return (1);
      if (my_getfloat(tab[i]) < -MAX_QUAD ||
	  my_getfloat(tab[i]) > MAX_QUAD)
	{
	  return (1);
	}
    }
  return (0);
}

int	set_obj_quad(t_obj *obj, char **tab, int nb_line)
{
  if (cnt_line_tab(tab) > 10 && !check_quadra(tab))
    {
      obj->parse.quad = 0;
      obj->quadra.a = my_getfloat(tab[1]);
      obj->quadra.b = my_getfloat(tab[2]);
      obj->quadra.c = my_getfloat(tab[3]);
      obj->quadra.d = my_getfloat(tab[4]);
      obj->quadra.e = my_getfloat(tab[5]);
      obj->quadra.f = my_getfloat(tab[6]);
      obj->quadra.g = my_getfloat(tab[7]);
      obj->quadra.h = my_getfloat(tab[8]);
      obj->quadra.i = my_getfloat(tab[9]);
      obj->quadra.j = my_getfloat(tab[10]);
      return (0);
    }
  obj->parse.quad = nb_line;
  return (1);
}
