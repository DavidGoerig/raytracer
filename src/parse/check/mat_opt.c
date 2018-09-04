/*
** mat_opt.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 25 15:43:50 2017 Benjamin
** Last update Thu May 25 18:57:47 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

void	fix_mat_transparency(t_mat *mat)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (mat->parse.transparency)
    {
      my_printf(EX_TRANS, mat->parse.transparency,
		mat->name, MAX_POS, MAX_POS);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_mat_transparency(mat, tab, mat->parse.transparency);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_mat_texture(t_mat *mat)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (mat->parse.texture)
    {
      my_printf(EX_TEXTURE, mat->parse.texture, mat->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_mat_texture(mat, tab, mat->parse.texture);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_mat_reflect(t_mat *mat)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (mat->parse.reflect)
    {
      my_printf(EX_REFLECT, mat->parse.reflect, mat->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_mat_reflect(mat, tab, mat->parse.reflect);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_mat_refract(t_mat *mat)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (mat->parse.refract)
    {
      my_printf(EX_REFRACT, mat->parse.refract, mat->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_mat_refract(mat, tab, mat->parse.refract);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_mat_shine(t_mat *mat)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (mat->parse.shine)
    {
      my_printf(EX_SHINE, mat->parse.shine, mat->name, MAX_SHINE);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_mat_shine(mat, tab, mat->parse.shine);
      free(str);
      my_free_tab(tab);
    }
}
