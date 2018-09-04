/*
** set_shine.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May 15 14:08:37 2017 Benjamin
** Last update Thu May 25 16:51:34 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_shine(t_mat *mat, char **tab, int nb_line)
{
  if (cnt_line_tab(tab) > 1 && !is_str_num(tab[1]) &&
      my_getnbr(tab[1]) >= 1 && my_getnbr(tab[1]) <= MAX_SHINE)
    {
      mat->parse.shine = 0;
      mat->shine = my_getnbr(tab[1]);
      return (0);
    }
  mat->parse.shine = nb_line;
  return (1);
}
