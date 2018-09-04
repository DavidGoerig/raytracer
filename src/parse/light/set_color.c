/*
** set_color.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/light/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Tue May 16 10:18:55 2017 Benjamin
** Last update Thu May 25 15:31:09 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_light_color(t_light *light, char **tab, int nb_line)
{
  if (cnt_line_tab(tab) > 3 && !is_str_num(tab[1]) && !is_str_num(tab[2])
      && !is_str_num(tab[3]) &&
      my_getnbr(tab[1]) >= 0 && my_getnbr(tab[1]) <= 255 &&
      my_getnbr(tab[2]) >= 0 && my_getnbr(tab[2]) <= 255 &&
      my_getnbr(tab[3]) >= 0 && my_getnbr(tab[3]) <= 255)
    {
      light->parse.color = 0;
      light->color.r = my_getnbr(tab[1]);
      light->color.g = my_getnbr(tab[2]);
      light->color.b = my_getnbr(tab[3]);
      light->color.a = 255;
      return (0);
    }
  light->parse.color = nb_line;
  return (1);
}
