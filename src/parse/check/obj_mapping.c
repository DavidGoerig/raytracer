/*
** obj_mapping.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Fri May 26 13:46:40 2017 Benjamin
** Last update Fri May 26 14:47:42 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

void	fix_obj_mapping(t_obj *obj)
{
  char	**tab;
  char	*str;

  str = NULL;
  if (!obj->parse.mat && obj->mapping != M_NONE)
    return ;
  while (obj->parse.mapping)
    {
      my_printf(EX_MAPPING, obj->parse.mapping, obj->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_obj_mapping(obj, tab, obj->parse.mapping);
      free(str);
      my_free_tab(tab);
    }
}
