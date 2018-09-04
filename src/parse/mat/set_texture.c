/*
** set_texture.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 25 18:15:55 2017 Benjamin
** Last update Thu May 25 20:05:39 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_texture(t_mat *mat, char **tab, int nb_line)
{
  if (cnt_line_tab(tab) > 1 && (mat->texture = loader_bmp(tab[1])))
    {
      mat->parse.texture = 0;
      return (0);
    }
  mat->parse.texture = nb_line;
  return (1);
}
