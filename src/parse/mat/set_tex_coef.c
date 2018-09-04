/*
** set_tex_coef.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Fri May 26 16:03:31 2017 Benjamin
** Last update Fri May 26 16:06:31 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_tex_coef(t_mat *mat, char **tab, int nb_line)
{
  (void)nb_line;
  if (cnt_line_tab(tab) > 1 && !is_str_num(tab[1]) &&
      my_getnbr(tab[1]) >= 0 && my_getnbr(tab[1]) <= MAX_MAX)
    mat->tex_coef = my_getnbr(tab[1]);
  return (0);
}
