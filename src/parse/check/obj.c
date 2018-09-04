/*
** obj.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Wed May 24 09:51:19 2017 Benjamin
** Last update Sun May 28 19:04:43 2017 Julien Delane
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

void	fix_obj_pos(t_obj *obj)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (obj->parse.pos)
    {
      my_printf(EX_POS, obj->parse.pos, obj->name, MAX_POS, MAX_POS);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_pos(obj, tab, obj->parse.pos);
      free(str);
      my_free_tab(tab);
    }
}

void	fix_obj_rot(t_obj *obj)
{
  char	**tab;
  char	*str;

  str = NULL;
  while (obj->parse.rot)
    {
      my_printf(EX_ROT, obj->parse.rot, obj->name, MAX_ROT, MAX_ROT);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_rot(obj, tab, obj->parse.rot);
      free(str);
      my_free_tab(tab);
    }
}

static void	fix_obj_name(t_obj *obj)
{
  char		*str;

  str = NULL;
  while (obj->parse.name)
    {
      my_printf(EX_NAME, obj->parse.name, obj->name);
      str = get_next_line(0);
      if (!is_str_anum(str))
	{
	  if (obj->name)
	    free (obj->name);
	  obj->name = my_strdup(str);
	  obj->parse.name = 0;
	}
      free(str);
    }
}

int	check_obj(t_obj *obj, t_mat *mat)
{
  int	ret;

  ret = 0;
  while (obj)
    {
      obj->parse.name ? fix_obj_name(obj) : 0;
      ret = fix_obj_mat(obj, mat);
      obj->parse.quad ? fix_obj_quad(obj) : 0;
      obj->parse.color ? fix_obj_color(obj) : 0;
      obj->parse.pos ? fix_obj_pos(obj) : 0;
      obj->parse.rot ? fix_obj_rot(obj) : 0;
      fix_obj_mapping(obj);
      obj = obj->next;
    }
  return (ret);
}
