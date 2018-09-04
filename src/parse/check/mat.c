/*
** mat.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Wed May 24 09:51:10 2017 Benjamin
** Last update Sun May 28 19:03:54 2017 Julien Delane
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

static void	fix_mat_name(t_mat *mat)
{
  char		*str;

  str = NULL;
  while (mat->parse.name)
    {
      my_printf(EX_NAME, mat->parse.name, mat->name);
      str = get_next_line(0);
      if (!is_str_anum(str))
	{
	  if (mat->name)
	    free (mat->name);
	  mat->name = my_strdup(str);
	  mat->parse.name = 0;
	}
      free(str);
    }
}

int	check_mat(t_mat *mat)
{
  while (mat)
    {
      mat->parse.name ? fix_mat_name(mat) : 0;
      mat->parse.transparency ? fix_mat_transparency(mat) : 0;
      mat->parse.reflect ? fix_mat_reflect(mat) : 0;
      mat->parse.refract ? fix_mat_refract(mat) : 0;
      mat->parse.shine ? fix_mat_shine(mat) : 0;
      mat->parse.texture ? fix_mat_texture(mat) : 0;
      mat = mat->next;
    }
  return (0);
}
