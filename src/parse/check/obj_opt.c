/*
** obj_opt.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 25 18:43:08 2017 Benjamin
** Last update Sat May 27 17:26:07 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

static int	check_obj_exist(char *name, t_mat *mat)
{
  t_mat		*tmp;

  if (!mat)
    {
      my_printf("Please add a material.\n");
      return (-1);
    }
  tmp = mat;
  while (tmp)
    {
      if (!my_strcmp(name, tmp->name))
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

int	fix_obj_mat(t_obj *obj, t_mat *mat)
{
  char	**tab;
  char	*str;
  int	ret;

  str = NULL;
  ret = check_obj_exist(obj->mat_name, mat);
  while (obj->parse.mat || ret)
    {
      my_printf(EX_MAT, obj->parse.mat, obj->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_mat(obj, tab, obj->parse.mat);
      free(str);
      my_free_tab(tab);
      ret = check_obj_exist(obj->mat_name, mat);
    }
  return (0);
}

void	fix_obj_quad(t_obj *obj)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (obj->parse.quad)
    {
      my_printf(EX_QUAD, obj->parse.quad, obj->name, MAX_QUAD, MAX_QUAD);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_quad(obj, tab, obj->parse.quad);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_obj_color(t_obj *obj)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (obj->parse.color)
    {
      my_printf(EX_COLOR, obj->parse.color, obj->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_color(obj, tab, obj->parse.color);
      free(str);
      my_free_tab(tab);
    }
}
