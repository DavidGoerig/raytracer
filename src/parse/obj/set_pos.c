/*
** set_pos.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:03 2017 Benjamin
** Last update Thu May 25 19:44:14 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_obj_pos(t_obj *obj, char **tab, int nb_line)
{
  if (tab && cnt_line_tab(tab) > 3 && !is_str_num(tab[1]) &&
      !is_str_num(tab[2]) && !is_str_num(tab[3]) &&
      my_getnbr(tab[1]) <= MAX_POS && my_getnbr(tab[1]) >= -MAX_POS &&
      my_getnbr(tab[2]) <= MAX_POS && my_getnbr(tab[2]) >= -MAX_POS &&
      my_getnbr(tab[3]) <= MAX_POS && my_getnbr(tab[3]) >= -MAX_POS)
    {
      obj->parse.pos = 0;
      obj->pos.x = my_getfloat(tab[1]);
      obj->pos.y = my_getfloat(tab[2]);
      obj->pos.z = my_getfloat(tab[3]);
      return (0);
    }
  obj->parse.pos = nb_line;
  return (1);
}
